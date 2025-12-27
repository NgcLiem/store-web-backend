import {
  Body,
  Controller,
  Post,
  Res,
  BadRequestException,
  InternalServerErrorException,
} from "@nestjs/common";
import type { Response } from "express";
import { OrdersService } from "../orders/orders.service";
import { MomoService } from "./momo.service";

@Controller("momo")
export class MomoController {
  constructor(
    private readonly orders: OrdersService,
    private readonly momo: MomoService,
  ) { }
  @Post("create-payment")
  async createPayment(@Body() body: any) {
    const internalOrderId = Number(body?.orderId);
    if (!internalOrderId) throw new BadRequestException("Thiếu orderId");

    const order = await this.orders.findOneWithItems(internalOrderId);
    if (!order) throw new BadRequestException("Order không tồn tại");

    const amount = Math.round(Number(order.total_amount ?? 0));
    if (amount < 1000) throw new BadRequestException("Số tiền tối thiểu 1000 VND");

    const orderInfo = `Thanh toan don hang #${internalOrderId}`;

    // set pending trước
    await this.orders.updatePaymentStatusByOrderId(internalOrderId, {
      status: "pending",
      payment_method: "momo",
    });

    // ✅ create MoMo payment
    const momoRes = await this.momo.createPayment({
      internalOrderId,
      amount,
      orderInfo,
    });

    // ✅ nên lưu momoOrderId/requestId để đối soát (nếu bạn có cột)
    // await this.orders.saveMomoMeta(internalOrderId, momoRes.momoOrderId, momoRes.requestId);

    return momoRes; // có payUrl
  }

  @Post("ipn")
  async ipn(@Body() body: any, @Res() res: Response) {
    try {
      const ok = this.momo.verifyIpnSignature(body);
      if (!ok) return res.status(204).send();

      const resultCode = Number(body.resultCode);

      // ✅ lấy internalOrderId từ extraData (ưu tiên)
      const meta = this.momo.decodeExtraData(body.extraData);
      let internalOrderId = Number(meta?.internalOrderId);

      // fallback: parse từ ORDER_{id}_...
      if (!internalOrderId && typeof body.orderId === "string") {
        const m = body.orderId.match(/^ORDER_(\d+)_/);
        if (m) internalOrderId = Number(m[1]);
      }

      if (!internalOrderId) return res.status(204).send();

      if (resultCode === 0) {
        await this.orders.updatePaymentStatusByOrderId(internalOrderId, { status: "confirmed" });
      } else {
        await this.orders.updatePaymentStatusByOrderId(internalOrderId, { status: "cancelled" });
      }

      return res.status(204).send();
    } catch (err) {
      console.error("IPN error:", err);
      return res.status(204).send();
    }
  }

}
