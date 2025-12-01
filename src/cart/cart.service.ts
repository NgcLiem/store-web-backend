import { Injectable, BadRequestException } from '@nestjs/common';
import { DbService } from '../db/db.service';

@Injectable()
export class CartService {
    constructor(private readonly db: DbService) { }

    // đảm bảo user có cart, nếu chưa thì tạo
    private async ensureCart(user_id: number): Promise<number> {
        const carts = await this.db.query<any>(
            'SELECT id FROM carts WHERE user_id = ? LIMIT 1',
            [user_id],
        );

        if (carts.length > 0) return carts[0].id;

        const result: any = await this.db.query(
            'INSERT INTO carts (user_id) VALUES (?)',
            [user_id],
        );
        return result.insertId || result[0]?.insertId;
    }

    // GET cart của user: join carts + cart_items + products
    async getUserCart(user_id: number) {
        if (!user_id) throw new BadRequestException('Thiếu user_id');

        const cartId = await this.ensureCart(user_id);

        const items = await this.db.query<any>(
            `
      SELECT 
        ci.id as cart_item_id,
        ci.quantity,
        p.id as product_id,
        p.name,
        p.price,
        p.image_url,
        p.stock
      FROM cart_items ci
      JOIN products p ON p.id = ci.product_id
      WHERE ci.cart_id = ?
      ORDER BY ci.id DESC
    `,
            [cartId],
        );

        return { cart_id: cartId, user_id, items };
    }

    // POST /cart  body: { user_id, product_id, quantity }
    async addItem(body: any) {
        const user_id = Number(body.user_id);
        const product_id = Number(body.product_id);
        const quantity = Number(body.quantity || 1);

        if (!user_id || !product_id) {
            throw new BadRequestException('Thiếu user_id hoặc product_id');
        }

        const cartId = await this.ensureCart(user_id);

        // kiểm tra xem đã có item cùng product_id trong cart chưa
        const existing = await this.db.query<any>(
            'SELECT id, quantity FROM cart_items WHERE cart_id = ? AND product_id = ?',
            [cartId, product_id],
        );

        if (existing.length > 0) {
            // update quantity
            const item = existing[0];
            const newQty = item.quantity + quantity;
            await this.db.query(
                'UPDATE cart_items SET quantity = ? WHERE id = ?',
                [newQty, item.id],
            );
        } else {
            await this.db.query(
                'INSERT INTO cart_items (cart_id, product_id, quantity) VALUES (?, ?, ?)',
                [cartId, product_id, quantity],
            );
        }

        return { ok: true, message: 'Đã thêm vào giỏ hàng' };
    }

    // PUT /cart/item/:id  (update quantity)
    async updateItem(cartItemId: number, body: any) {
        const quantity = Number(body.quantity);

        if (!cartItemId) throw new BadRequestException('Thiếu cartItemId');
        if (!quantity || quantity <= 0) {
            throw new BadRequestException('Số lượng phải > 0');
        }

        await this.db.query('UPDATE cart_items SET quantity = ? WHERE id = ?', [
            quantity,
            cartItemId,
        ]);
        return { ok: true, message: 'Cập nhật giỏ hàng thành công' };
    }

    // DELETE /cart/item/:id
    async removeItem(cartItemId: number) {
        if (!cartItemId) throw new BadRequestException('Thiếu cartItemId');
        await this.db.query('DELETE FROM cart_items WHERE id = ?', [cartItemId]);
        return { ok: true, message: 'Đã xoá sản phẩm khỏi giỏ' };
    }

    // DELETE /cart/clear?user_id=3
    async clearUserCart(user_id: number) {
        if (!user_id) throw new BadRequestException('Thiếu user_id');

        const carts = await this.db.query<any>(
            'SELECT id FROM carts WHERE user_id = ? LIMIT 1',
            [user_id],
        );
        if (carts.length === 0) return { ok: true, message: 'Giỏ hàng đã rỗng' };

        const cartId = carts[0].id;
        await this.db.query('DELETE FROM cart_items WHERE cart_id = ?', [cartId]);
        return { ok: true, message: 'Đã xoá toàn bộ giỏ hàng' };
    }
}
