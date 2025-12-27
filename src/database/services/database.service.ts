import { Injectable, OnModuleDestroy } from '@nestjs/common';
import { createPool, Pool } from 'mysql2/promise';
import * as dotenv from 'dotenv';

dotenv.config();

@Injectable()
export class DatabaseService implements OnModuleDestroy {
    private pool: Pool;

    constructor() {
        this.pool = createPool({
            host: process.env.DB_HOST || 'localhost',
            user: process.env.DB_USER || 'root',
            password: process.env.DB_PASSWORD || '123456',
            database: process.env.DB_NAME || 'shoe_shop',
            port: Number(process.env.DB_PORT) || 3306,
            connectionLimit: 10,
        });
    }

    async query<T = any>(sql: string, params: any[] = []): Promise<T[]> {
        const [rows] = await this.pool.query(sql, params);
        return rows as T[];
    }

    async onModuleDestroy() {
        await this.pool.end();
    }
}
