import {
    Controller,
    Get,
    Param,
    Query,
    ParseIntPipe,
    Post,
    Body,
    Put,
    Delete,
} from '@nestjs/common';
import { ProductsService } from './products.service';

@Controller('products')
export class ProductsController {
    constructor(private readonly service: ProductsService) { }

    // GET /products?q=abc
    @Get()
    async getAll(@Query('q') q?: string) {
        return this.service.findAll(q);
    }

    // GET /products/:id
    @Get(':id')
    async getOne(@Param('id', ParseIntPipe) id: number) {
        return this.service.findOne(id);
    }

    // POST /products
    @Post()
    async create(@Body() body: any) {
        return this.service.create(body);
    }

    // PUT /products/:id
    @Put(':id')
    async update(@Param('id', ParseIntPipe) id: number, @Body() body: any) {
        return this.service.update(id, body);
    }

    // DELETE /products/:id
    @Delete(':id')
    async remove(@Param('id', ParseIntPipe) id: number) {
        return this.service.remove(id);
    }
}
