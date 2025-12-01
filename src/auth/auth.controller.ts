import { Controller, Post, Body, Get, UseGuards, Req } from '@nestjs/common';
import { AuthService } from './auth.service';
import { JwtAuthGuard } from './jwt-auth.guard';

@Controller('auth')
export class AuthController {
    constructor(private authService: AuthService) { }

    @Post('login')
    async login(@Body() body: any) {
        const { email, password } = body;
        return this.authService.login(email, password);
    }

    @Post('register')
    async register(@Body() body: any) {
        const { email, password, fullName, phone, address, sex } = body;
        return this.authService.register({ email, password, fullName, phone, address, sex });
    }

    @Post('reset-password')
    async resetPassword(@Body() body: any) {
        const { token, newPassword } = body;
        return this.authService.resetPassword(token, newPassword);
    }

    @Post('forgot-password')
    async forgotPassword(@Body('email') email: string) {
        return this.authService.forgotPassword(email);
    }

    @UseGuards(JwtAuthGuard)
    @Get('me')
    getMe(@Req() req) {
        return {
            user: req.user,
        };
    }
}
