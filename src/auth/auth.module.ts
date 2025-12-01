import { Module } from '@nestjs/common';
import { JwtModule } from '@nestjs/jwt';
import { AuthController } from './auth.controller';
import { AuthService } from './auth.service';
import { JwtStrategy } from './jwt.strategy';
import { DbModule } from '../db/db.module';
import { MailModule } from '../mail/mail.module';

@Module({
    imports: [
        DbModule,
        MailModule,
        JwtModule.register({
            secret: 'SECRET_KEY',
            signOptions: { expiresIn: '1h' },
        }),
    ],
    controllers: [AuthController],
    providers: [AuthService, JwtStrategy],
    exports: [AuthService],
})
export class AuthModule { }
