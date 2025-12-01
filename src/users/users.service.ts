import { Injectable } from '@nestjs/common';
import { DbService } from '../db/db.service';

@Injectable()
export class UsersService {
    constructor(private readonly db: DbService) { }

    async findAll() {
        return this.db.query('SELECT * FROM users');
    }

    async findOne(id: number) {
        const rows = await this.db.query('SELECT * FROM users WHERE id = ?', [id]);
        return rows[0] || null;
    }
}
