import { MiddlewareConsumer, Module, NestModule, RequestMethod } from '@nestjs/common';
import { ServeStaticModule } from '@nestjs/serve-static';
import { join } from 'path';

import { LoggerMiddleware, RequestIdMiddleware } from './common/middleware';

import { AuthModule } from './modules/auth/auth.module';
import { DatabaseModule } from './database/database.module';

import { ProductsModule } from './modules/products/products.module';
import { UsersModule } from './modules/users/users.module';
import { OrdersModule } from './modules/orders/orders.module';
import { CartModule } from './modules/cart/cart.module';
import { StaffModule } from './modules/staff/staff.module';
import { AddressesModule } from './modules/addresses/addresses.module';
import { CloudinaryModule } from './modules/cloudinary/cloudinary.module';
import { UploadModule } from './modules/upload/upload.module';
import { PaymentMethodsModule } from './modules/payment-method/payment-method.module';
import { VouchersModule } from './modules/vouchers/vouchers.module';
import { MomoModule } from './modules/momo/momo.module';
import { MailModule } from './modules/mail/mail.module';

import { JwtStrategy } from './modules/auth/strategies/jwt.strategy';

@Module({
  imports: [
    AuthModule,
    DatabaseModule,
    ProductsModule,
    UsersModule,
    OrdersModule,
    CartModule,
    StaffModule,
    AddressesModule,
    CloudinaryModule,
    UploadModule,
    PaymentMethodsModule,
    VouchersModule,
    MomoModule,
    MailModule,
    ServeStaticModule.forRoot({
      rootPath: join(__dirname, '..', 'uploads'),
      serveRoot: '/uploads',
    }),
  ],
  providers: [JwtStrategy],
})
export class AppModule implements NestModule {
  configure(consumer: MiddlewareConsumer) {
    consumer
      .apply(RequestIdMiddleware, LoggerMiddleware)
      .forRoutes({ path: '*', method: RequestMethod.ALL });
  }
}
