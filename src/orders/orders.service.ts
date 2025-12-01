import {
    Injectable,
    BadRequestException,
    NotFoundException,
} from '@nestjs/common';
import { DbService } from '../db/db.service';

export interface Order {
    id: number;
    user_id: number | null;
    order_date: Date | null;
    total_amount: number | null;
    status: 'pending' | 'confirmed' | 'shipped' | 'delivered' | 'cancelled';
    shipping_address: string | null;
    payment_method: 'cod' | 'credit_card' | 'bank_transfer';
}

export interface OrderItem {
    id: number;
    order_id: number | null;
    product_id: number | null;
    quantity: number | null;
    price: number | null;
}

@Injectable()
export class OrdersService {
    constructor(private readonly db: DbService) { }

    // GET /orders?user_id=3&status=pending
    async findAll(params: { user_id?: number; status?: string } = {}) {
        const { user_id, status } = params;
        let sql = 'SELECT * FROM orders WHERE 1=1';
        const values: any[] = [];

        if (user_id) {
            sql += ' AND user_id = ?';
            values.push(user_id);
        }

        if (status) {
            sql += ' AND status = ?';
            values.push(status);
        }

        sql += ' ORDER BY order_date DESC';

        return this.db.query<Order>(sql, values);
    }

    // GET /orders/:id (trả cả order + items)
    async findOneWithItems(id: number) {
        if (!id) throw new BadRequestException('Thiếu id');

        const orders = await this.db.query<Order>(
            'SELECT * FROM orders WHERE id = ?',
            [id],
        );
        if (orders.length === 0) {
            throw new NotFoundException('Không tìm thấy đơn hàng');
        }
        const order = orders[0];

        const items = await this.db.query<any>(
            `
      SELECT oi.*, p.name, p.image_url
      FROM order_items oi
      JOIN products p ON p.id = oi.product_id
      WHERE oi.order_id = ?
    `,
            [id],
        );

        return { ...order, items };
    }

    // body: { user_id, shipping_address, payment_method, items: [{product_id, quantity}] }
    async create(body: any) {
        const { user_id, shipping_address, payment_method, items } = body;

        if (!user_id) {
            throw new BadRequestException('Thiếu user_id');
        }
        if (!items || !Array.isArray(items) || items.length === 0) {
            throw new BadRequestException('Đơn hàng phải có ít nhất 1 sản phẩm');
        }

        const productIds = items.map((it: any) => it.product_id).filter(Boolean);
        if (productIds.length === 0) {
            throw new BadRequestException('Danh sách sản phẩm không hợp lệ');
        }

        // Lấy giá hiện tại của sản phẩm
        const products = await this.db.query<any>(
            `SELECT id, price FROM products WHERE id IN (${productIds
                .map(() => '?')
                .join(',')})`,
            productIds,
        );

        const priceMap = new Map<number, number>();
        products.forEach((p: any) => priceMap.set(p.id, Number(p.price)));

        let total = 0;
        const orderItemsToInsert: { product_id: number; quantity: number; price: number }[] =
            [];

        for (const item of items) {
            const pid = Number(item.product_id);
            const qty = Number(item.quantity || 1);
            const price = priceMap.get(pid);

            if (!price) {
                throw new BadRequestException(`Sản phẩm id=${pid} không tồn tại hoặc không có giá`);
            }

            total += price * qty;
            orderItemsToInsert.push({ product_id: pid, quantity: qty, price });
        }

        // Tạo order
        const insertOrderSql = `
      INSERT INTO orders (user_id, total_amount, status, shipping_address, payment_method)
      VALUES (?, ?, ?, ?, ?)
    `;
        const orderParams = [
            user_id,
            total,
            'pending',
            shipping_address || null,
            payment_method || 'cod',
        ];

        const result: any = await this.db.query(insertOrderSql, orderParams);
        const orderId = result.insertId || result[0]?.insertId;

        // Tạo order_items
        const itemSql = `
      INSERT INTO order_items (order_id, product_id, quantity, price)
      VALUES (?, ?, ?, ?)
    `;
        for (const oi of orderItemsToInsert) {
            await this.db.query(itemSql, [orderId, oi.product_id, oi.quantity, oi.price]);
        }

        return { ok: true, id: orderId, total_amount: total };
    }

    async update(id: number, body: Partial<Order>) {
        if (!id) throw new BadRequestException('Thiếu id');

        const fields = ['total_amount', 'status', 'shipping_address', 'payment_method'];
        const updates: string[] = [];
        const values: any[] = [];

        for (const field of fields) {
            if (body[field as keyof Order] !== undefined) {
                updates.push(`${field} = ?`);
                values.push(body[field as keyof Order]);
            }
        }

        if (updates.length === 0) {
            throw new BadRequestException('Không có dữ liệu cập nhật');
        }

        values.push(id);
        const sql = `UPDATE orders SET ${updates.join(', ')} WHERE id = ?`;
        await this.db.query(sql, values);

        return { ok: true, message: 'Cập nhật đơn hàng thành công' };
    }

    async remove(id: number) {
        if (!id) throw new BadRequestException('Thiếu id');

        // Xoá order_items trước
        await this.db.query('DELETE FROM order_items WHERE order_id = ?', [id]);
        // Xoá orders
        await this.db.query('DELETE FROM orders WHERE id = ?', [id]);

        return { ok: true, message: 'Đã xoá đơn hàng' };
    }
}
