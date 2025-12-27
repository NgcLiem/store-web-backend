import { Injectable, UnauthorizedException, BadRequestException } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { DatabaseService } from '../../database/services/database.service';
import * as bcrypt from 'bcrypt';
import * as crypto from 'crypto';
import { MailService } from '../mail/mail.service';

@Injectable()
export class AuthService {
    constructor(
        private jwtService: JwtService,
        private db: DatabaseService,
        private mailService: MailService,
    ) { }

    async login(email: string, password: string) {
        console.log('LOGIN INPUT:', email);

        const rows = await this.db.query<any>(
            'SELECT id, email, password, role, status FROM users WHERE email = ? LIMIT 1',
            [email],
        );

        console.log('LOGIN ROWS:', rows);

        const user = rows[0];

        if (!user) {
            throw new UnauthorizedException('Email không tồn tại');
        }

        if (user.status !== 'active') {
            throw new UnauthorizedException('Tài khoản của bạn đang bị khoá hoặc chưa được kích hoạt');
        }

        const match = await bcrypt.compare(password, user.password);
        console.log('PASSWORD MATCH =', match);

        if (!match) {
            throw new UnauthorizedException('Sai mật khẩu');
        }

        const payload = {
            id: user.id,
            email: user.email,
            role: user.role,
        };

        const token = this.jwtService.sign(payload, {
            secret: 'SECRET_KEY',
            expiresIn: '1h',
        });

        console.log('LOGIN SUCCESS, payload =', payload);

        return {
            user: payload,
            token,
            expiresIn: 3600,
        };
    }

    async register(dto: { email: string; password: string; fullName: string; phone: string; address: string; sex: string; }) {
        const { email, password, fullName, phone, address, sex } = dto;

        if (!email || !password || !fullName || !phone || !address || !sex) {
            throw new BadRequestException('Thiếu thông tin!');
        }

        const existing = await this.db.query<any>(
            'SELECT id FROM users WHERE email = ? LIMIT 1',
            [email],
        );

        if (existing.length > 0) {
            throw new BadRequestException('Email đã tồn tại!');
        }

        const hashedPassword = await bcrypt.hash(password, 10);

        const insertResult: any = await this.db.query(
            'INSERT INTO users (email, password, full_name, phone, address, role, sex) VALUES (?, ?, ?, ?, ?, ?, ?)',
            [email, hashedPassword, fullName, phone, address, 'customer', sex],
        );

        const newUserId =
            insertResult?.insertId ?? insertResult?.[0]?.insertId ?? null;

        if (newUserId) {
            await this.db.query('INSERT INTO carts (user_id) VALUES (?)', [
                newUserId,
            ]);
        }

        return {
            message: 'Đăng ký thành công! Vui lòng đăng nhập.',
        };
    }

    async resetPassword(token: string, newPassword: string) {
        if (!token || !newPassword) {
            throw new BadRequestException('Thiếu dữ liệu!');
        }

        const rows = await this.db.query<any>(
            'SELECT * FROM users WHERE reset_token = ? AND reset_expires > NOW()',
            [token],
        );

        if (!rows || rows.length === 0 || rows[0].status !== 'active') {
            throw new BadRequestException('Token không hợp lệ hoặc đã hết hạn!');
        }

        const user = rows[0];

        const hashed = await bcrypt.hash(newPassword, 10);

        await this.db.query(
            'UPDATE users SET password = ?, reset_token = NULL, reset_expires = NULL WHERE id = ?',
            [hashed, user.id],
        );

        return { message: 'Đặt lại mật khẩu thành công!' };
    }

    async forgotPassword(email: string) {
        if (!email) {
            throw new BadRequestException('Thiếu email!');
        }

        const rows = await this.db.query<any>(
            'SELECT id, email, status FROM users WHERE email = ? LIMIT 1',
            [email],
        );

        if (!rows || rows.length === 0 || rows[0].status !== 'active') {
            return {
                message:
                    'Nếu email tồn tại, link đặt lại mật khẩu đã được gửi. Hãy kiểm tra hộp thư của bạn.',
            };
        }

        const user = rows[0];

        const token = crypto.randomBytes(32).toString('hex');
        const EXPIRE_MINUTES = 15;

        await this.db.query(
            'UPDATE users SET reset_token = ?, reset_expires = DATE_ADD(NOW(), INTERVAL ? MINUTE) WHERE id = ?',
            [token, EXPIRE_MINUTES, user.id],
        );

        const frontendUrl = process.env.FRONTEND_URL || 'http://localhost:3000';
        const resetLink = `${frontendUrl}/reset-password?token=${token}`;

        await this.mailService.sendResetPasswordMail(email, resetLink);

        return {
            message:
                'Nếu email tồn tại, link đặt lại mật khẩu đã được gửi. Hãy kiểm tra hộp thư của bạn.',
        };
    }


}
