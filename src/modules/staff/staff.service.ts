import { Injectable, BadRequestException } from '@nestjs/common';
import { DatabaseService } from '../../database/services/database.service';
import * as bcrypt from 'bcrypt';

export interface Staff {
    id: number;
    email: string;
    password: string;
    full_name: string;
    phone: string | null;
    address: string | null;
    role: 'customer' | 'staff' | 'admin';
    created_at: Date | null;
    sex: string | null;
    status: string;
}

@Injectable()
export class StaffService {
    constructor(private readonly db: DatabaseService) {}

    async findAll(q?: string) {
        let sql = "SELECT * FROM users WHERE role = 'staff'";
        const values: any[] = [];

        if (q) {
            const like = `%${q}%`;
            sql += ' AND (email LIKE ? OR full_name LIKE ?)';
            values.push(like, like);
        }

        sql += ' ORDER BY id DESC';

        return this.db.query<Staff>(sql, values);
    }

    async findOne(id: number) {
        const rows = await this.db.query<Staff>(
            "SELECT * FROM users WHERE id = ? AND role = 'staff'",
            [id],
        );
        return rows[0] || null;
    }

    async create(body: Partial<Staff>) {
        if (!body.email || !body.password || !body.full_name) {
            throw new BadRequestException(
                'Thiếu email, password hoặc full_name',
            );
        }

        const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
        if (!emailRegex.test(body.email)) {
            throw new BadRequestException('Email không đúng định dạng');
        }

        // kiểm tra email trùng
        const existing = await this.db.query<any>(
            'SELECT id FROM users WHERE email = ?',
            [body.email],
        );
        if (existing.length > 0) {
            throw new BadRequestException('Email đã tồn tại');
        }

        const saltRounds = 10;
        const hashedPassword = await bcrypt.hash(body.password, saltRounds);
        const sql = `
      INSERT INTO users (email, password, full_name, phone, address, role, sex, status)
      VALUES (?, ?, ?, ?, ?, 'staff', ?, 'active')
    `;
        const params = [
            body.email,
            hashedPassword,
            body.full_name,
            body.phone || null,
            body.address || null,
            body.sex || null,
            body.status || null,
        ];

        await this.db.query(sql, params);
        return { ok: true, message: 'Đã tạo nhân viên' };
    }

    async update(id: number, body: Partial<Staff>) {
        if (!id) throw new BadRequestException('Thiếu id');

        if (body.password) {
            const saltRounds = 10;
            body.password = await bcrypt.hash(body.password, saltRounds);
        }
        const fields = [
            'email',
            'password',
            'full_name',
            'phone',
            'address',
            'sex',
            'status',
        ];
        const updates: string[] = [];
        const values: any[] = [];

        for (const field of fields) {
            if (body[field as keyof Staff] !== undefined) {
                updates.push(`${field} = ?`);
                values.push(body[field as keyof Staff]);
            }
        }

        if (updates.length === 0) {
            throw new BadRequestException('Không có dữ liệu cập nhật');
        }

        values.push(id);
        const sql = `UPDATE users SET ${updates.join(', ')} WHERE id = ? AND role = 'staff'`;
        await this.db.query(sql, values);

        return { ok: true, message: 'Cập nhật nhân viên thành công' };
    }

    async remove(id: number) {
        if (!id) throw new BadRequestException('Thiếu id');
        await this.db.query(
            "DELETE FROM users WHERE id = ? AND role = 'staff'",
            [id],
        );
        return { ok: true, message: 'Đã xoá nhân viên' };
    }
}
