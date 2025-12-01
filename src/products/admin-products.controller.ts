import { Controller, Get, Post, Put, Delete, Param, Body, Query, ParseIntPipe, UseGuards } from '@nestjs/common';
import { ProductsService } from './products.service';
import { Roles } from '../auth/roles.decorator';
import { RolesGuard } from '../auth/roles.guard';
import { JwtAuthGuard } from '../auth/jwt-auth.guard'

@UseGuards(JwtAuthGuard, RolesGuard,)
@Roles('admin')
@Controller('admin/products')

export class AdminProductsController {
    constructor(private readonly productsService: ProductsService) { }

    @Get()
    findAll(@Query('q') q?: string) {
        return this.productsService.findAll(q);
    }

    @Post()
    create(@Body() dto: any) {
        return this.productsService.create(dto);
    }

    @Put(':id')
    update(
        @Param('id', ParseIntPipe) id: number,
        @Body() dto: any,
    ) {
        return this.productsService.update(id, dto);
    }

    @Delete(':id')
    remove(@Param('id', ParseIntPipe) id: number) {
        return this.productsService.remove(id);
    }
}
