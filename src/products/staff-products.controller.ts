import { Controller, Get, Put, Param, Body, Query, ParseIntPipe, UseGuards } from '@nestjs/common';
import { ProductsService } from './products.service';
import { Roles } from '../auth/roles.decorator';
import { RolesGuard } from '../auth/roles.guard';
import { JwtAuthGuard } from '../auth/jwt-auth.guard';

@UseGuards(JwtAuthGuard, RolesGuard)
@Roles('staff')
@Controller('staff/products')
export class StaffProductsController {
    constructor(private readonly productsService: ProductsService) { }

    @Get()
    findAll(@Query('q') q?: string, @Query('category') category?: string,) {
        return this.productsService.findAll(q, category);
    }

    @Put(':id/stock')
    updateStock(
        @Param('id', ParseIntPipe) id: number,
        @Body('stock') stock: number,
    ) {
        return this.productsService.updateStock(id, Number(stock));
    }
}
