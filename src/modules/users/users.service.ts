import { Injectable } from '@nestjs/common';
import { DatabaseService } from '../../database/services/database.service';

@Injectable()
export class UsersService {
    constructor(private readonly db: DatabaseService) {}

    async findAll(q?: string) {
        let sql = 'SELECT * FROM users WHERE 1=1';
        const params: any[] = [];

        if (q && q.trim() !== '') {
            sql += ' AND (email LIKE ? OR full_name LIKE ? OR phone LIKE ?)';
            const term = `%${q.trim()}%`;
            params.push(term, term, term);
        }

        sql += ' ORDER BY id DESC';

        return this.db.query(sql, params);
    }

    async findOne(id: number) {
        const rows = await this.db.query('SELECT * FROM users WHERE id = ?', [
            id,
        ]);
        return rows[0] || null;
    }

    async updateStatus(id: number, status: string) {
        const normalized =
            status === 'active' || status === 'inactive'
                ? status
                : status
                  ? 'active'
                  : 'inactive';

        await this.db.query('UPDATE users SET status = ? WHERE id = ?', [
            normalized,
            id,
        ]);

        return { id, status: normalized };
    }
}
