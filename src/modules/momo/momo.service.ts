import { Injectable, InternalServerErrorException } from "@nestjs/common";
import axios from "axios";
import * as crypto from "crypto";

type CreatePaymentParams = {
    internalOrderId: number;     // ID trong DB
    amount: number;
    orderInfo: string;
    extraData?: string;          // base64 (optional)
};

@Injectable()
export class MomoService {
    private get partnerCode() { return process.env.MOMO_PARTNER_CODE ?? ""; }
    private get accessKey() { return process.env.MOMO_ACCESS_KEY ?? ""; }
    private get secretKey() { return process.env.MOMO_SECRET_KEY ?? ""; }
    private get redirectUrl() { return process.env.MOMO_REDIRECT_URL ?? ""; }
    private get ipnUrl() { return process.env.MOMO_IPN_URL ?? ""; }

    private get endpoint() {
        // sandbox
        const base = process.env.MOMO_BASE_URL ?? "https://test-payment.momo.vn";
        return `${base}/v2/gateway/api/create`;
    }

    private sign(raw: string) {
        return crypto.createHmac("sha256", this.secretKey).update(raw).digest("hex");
    }

    async createPayment(params: CreatePaymentParams) {
        if (!this.partnerCode || !this.accessKey || !this.secretKey || !this.redirectUrl || !this.ipnUrl) {
            throw new InternalServerErrorException("Thiếu cấu hình MOMO_* trong .env");
        }

        const requestType = "captureWallet"; // ví MoMo (dễ demo nhất, luôn trả payUrl nếu OK)
        const lang = "vi";

        // ✅ requestId nên unique
        const requestId = `${params.internalOrderId}-${Date.now()}`;

        // ✅ momoOrderId phải unique (đây là cái MoMo check trùng)
        const momoOrderId = `ORDER_${params.internalOrderId}_${Date.now()}`;

        const amountStr = String(Math.round(params.amount));

        // ✅ extraData: nhét internalOrderId để IPN về bạn map đúng (base64 JSON)
        const extraData =
            params.extraData ??
            Buffer.from(JSON.stringify({ internalOrderId: params.internalOrderId }), "utf8").toString("base64");

        const rawSignature =
            `accessKey=${this.accessKey}` +
            `&amount=${amountStr}` +
            `&extraData=${extraData}` +
            `&ipnUrl=${this.ipnUrl}` +
            `&orderId=${momoOrderId}` +
            `&orderInfo=${params.orderInfo}` +
            `&partnerCode=${this.partnerCode}` +
            `&redirectUrl=${this.redirectUrl}` +
            `&requestId=${requestId}` +
            `&requestType=${requestType}`;

        const signature = this.sign(rawSignature);

        const requestBody = {
            partnerCode: this.partnerCode,
            accessKey: this.accessKey,
            requestId,
            amount: amountStr,
            orderId: momoOrderId,
            orderInfo: params.orderInfo,
            redirectUrl: this.redirectUrl,
            ipnUrl: this.ipnUrl,
            extraData,
            requestType,
            lang,
            signature,
        };

        try {
            const { data } = await axios.post(this.endpoint, requestBody, {
                headers: { "Content-Type": "application/json" },
                timeout: 30000,
            });

            // ✅ nếu lỗi thì MoMo trả resultCode != 0 và thường không có payUrl
            if (!data || Number(data.resultCode) !== 0) {
                console.error("MoMo create-payment failed:", data);
                throw new InternalServerErrorException(data?.message ?? "MoMo create-payment failed");
            }

            // data.payUrl, data.qrCodeUrl...
            return {
                ...data,
                momoOrderId,
                requestId,
            };
        } catch (err: any) {
            const momoMsg = err?.response?.data ?? err?.message;
            console.error("MoMo create-payment error:", momoMsg);
            throw new InternalServerErrorException("Không thể tạo thanh toán MoMo");
        }
    }

    verifyIpnSignature(body: any): boolean {
        if (!this.accessKey || !this.secretKey) return false;

        const rawSignature =
            `accessKey=${this.accessKey}` +
            `&amount=${body.amount}` +
            `&extraData=${body.extraData ?? ""}` +
            `&message=${body.message}` +
            `&orderId=${body.orderId}` +
            `&orderInfo=${body.orderInfo}` +
            `&orderType=${body.orderType}` +
            `&partnerCode=${body.partnerCode}` +
            `&payType=${body.payType}` +
            `&requestId=${body.requestId}` +
            `&responseTime=${body.responseTime}` +
            `&resultCode=${body.resultCode}` +
            `&transId=${body.transId}`;

        const expected = this.sign(rawSignature);
        return expected === body.signature;
    }

    decodeExtraData(extraData?: string) {
        try {
            if (!extraData) return null;
            const json = Buffer.from(extraData, "base64").toString("utf8");
            return JSON.parse(json);
        } catch {
            return null;
        }
    }
}
