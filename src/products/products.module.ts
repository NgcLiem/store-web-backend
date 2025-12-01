import { Module } from '@nestjs/common';
import { ProductsController } from './products.controller';
import { ProductsService } from './products.service';
import { DbModule } from '../db/db.module';
import { AdminProductsController } from './admin-products.controller';
import { StaffProductsController } from './staff-products.controller';

@Module({
  imports: [DbModule],
  controllers: [
    AdminProductsController,   // route: /admin/products
    StaffProductsController,   // route: /staff/products
  ],
  providers: [ProductsService],
})
export class ProductsModule { }
