import { Injectable, NotFoundException, BadRequestException } from '@nestjs/common';
import { DatabaseService } from '../../database/services/database.service';

export interface Product {
    id: number;
    product_code?: string;
    name: string;
    price: number;
    description?: string;
    image?: string;
    image_url?: string;
    category_id?: number;
    stock?: number;
}

@Injectable()
export class ProductsService {
    constructor(private readonly db: DatabaseService) { }

    async findAll(q?: string, category?: string | number): Promise<Product[]> {
        const conditions: string[] = [];
        const params: any[] = [];

        if (q) {
            const like = `%${q}%`;
            conditions.push('(name LIKE ? OR product_code LIKE ?)');
            params.push(like, like);
        }

        if (category && category !== 'all') {
            conditions.push('category_id = ?');
            params.push(Number(category));
        }

        let sql = 'SELECT * FROM products';
        if (conditions.length > 0) {
            sql += ' WHERE ' + conditions.join(' AND ');
        }

        return this.db.query<Product>(sql, params);
    }


    async findOne(id: number): Promise<Product> {
        if (!id) throw new BadRequestException('Thiếu id');

        const rows = await this.db.query<Product>(
            'SELECT * FROM products WHERE id = ?',
            [id],
        );
        if (rows.length === 0) {
            throw new NotFoundException('Không tìm thấy sản phẩm');
        }
        return rows[0];
    }

    async create(body: Partial<Product>) {
        if (!body.name || body.price === undefined) {
            throw new BadRequestException('Thiếu name hoặc price');
        }

        const sql =
            'INSERT INTO products (product_code, name, price, description, image, image_url, category_id, stock) VALUES (?, ?, ?, ?, ?, ?, ?, ?)';
        const params = [
            body.product_code || null,
            body.name,
            body.price,
            body.description || null,
            body.image || null,
            body.image_url || null,
            body.category_id || null,
            body.stock ?? 0,
        ];

        const result: any = await this.db.query(sql, params);
        const insertId = result.insertId || result[0]?.insertId;

        return {
            ok: true,
            id: insertId,
        };
    }

    async update(id: number, body: Partial<Product>) {
        if (!id) throw new BadRequestException('Thiếu id');

        const fields = [
            'product_code',
            'name',
            'price',
            'description',
            'image',
            'image_url',
            'category_id',
            'stock',
        ];
        const updates: string[] = [];
        const values: any[] = [];

        for (const field of fields) {
            if (body[field as keyof Product] !== undefined) {
                updates.push(`${field} = ?`);
                values.push(body[field as keyof Product]);
            }
        }

        if (updates.length === 0) {
            throw new BadRequestException('Không có dữ liệu cập nhật');
        }

        values.push(id);
        const sql = `UPDATE products SET ${updates.join(', ')} WHERE id = ?`;
        await this.db.query(sql, values);

        return { ok: true, message: 'Cập nhật thành công' };
    }

    async remove(id: number) {
        if (!id) throw new BadRequestException('Thiếu id');

        await this.db.query('DELETE FROM products WHERE id = ?', [id]);
        return { ok: true, message: 'Đã xoá sản phẩm' };
    }

    async updateStock(id: number, stock: number) {
        if (!id) throw new BadRequestException('Thiếu id');

        await this.db.query(
            'UPDATE products SET stock = ? WHERE id = ?',
            [stock, id],
        );

        return { ok: true, message: 'Đã cập nhật tồn kho' };
    }

    async autocomplete(keyword: string) {
        if (!keyword || keyword.length < 2) {
            return [];
        }

        const like = `%${keyword}%`;
        const sql = `
    SELECT DISTINCT p.name, p.product_code, p.id
    FROM products p
    LEFT JOIN categories c ON p.category_id = c.id
    WHERE p.name LIKE ? OR p.product_code LIKE ? OR c.name LIKE ?
    LIMIT 8
  `;
        return this.db.query(sql, [like, like, like]);
    }

    // Search cho trang /search
    async search(params: {
        query?: string;
        page?: number;
        limit?: number;
        sort?: 'newest' | 'price_asc' | 'price_desc';
    }) {
        const query = (params.query || '').trim();
        const page = Math.max(params.page || 1, 1);
        let limit = params.limit || 12;
        limit = Math.min(Math.max(limit, 1), 48); // 1–48
        const offset = (page - 1) * limit;

        if (!query) {
            throw new BadRequestException('Thiếu từ khóa tìm kiếm');
        }

        const like = `%${query}%`;
        const whereParts: string[] = [
            '(p.name LIKE ? OR p.product_code LIKE ? OR c.name LIKE ?)',
        ];
        const whereParams: any[] = [like, like, like];

        let orderBy = 'p.created_at DESC';
        switch (params.sort) {
            case 'price_asc':
                orderBy = 'p.price ASC';
                break;
            case 'price_desc':
                orderBy = 'p.price DESC';
                break;
            default:
                orderBy = 'p.created_at DESC';
        }

        const where = 'WHERE ' + whereParts.join(' AND ');

        const itemsSql = `
      SELECT 
        p.id,
        p.product_code,
        p.name,
        p.price,
        p.image_url,
        p.stock,
        p.is_hot,
        c.name AS category
      FROM products p
      LEFT JOIN categories c ON p.category_id = c.id
      ${where}
      ORDER BY ${orderBy}
      LIMIT ? OFFSET ?
    `;
        const items = await this.db.query(itemsSql, [
            ...whereParams,
            limit,
            offset,
        ]);

        const countSql = `
      SELECT COUNT(*) AS total
      FROM products p
      LEFT JOIN categories c ON p.category_id = c.id
      ${where}
    `;
        const countRows: any[] = await this.db.query(countSql, whereParams);
        const total = Number(countRows[0]?.total || 0);

        return {
            items,
            total,
            page,
            limit,
        };
    }
}
