import {
    Controller,
    Get,
    Param,
    ParseIntPipe,
    Query,
    Post,
    Body,
    Put,
    Delete,
} from '@nestjs/common';
import { OrdersService } from './orders.service';

@Controller('orders')
export class OrdersController {
    constructor(private readonly service: OrdersService) { }

    // GET /orders?user_id=3&status=pending
    @Get()
    getAll(
        @Query('user_id') userId?: string,
        @Query('status') status?: string,
    ) {
        const user_id = userId ? Number(userId) : undefined;
        const safeStatus = status === 'all' ? undefined : status;
        return this.service.findAll({ user_id, status: safeStatus });
    }

    // GET /orders/:id  (trả order + items)
    @Get(':id')
    getOne(@Param('id', ParseIntPipe) id: number) {
        return this.service.findOneWithItems(id);
    }

    // POST /orders
    @Post()
    create(@Body() body: any) {
        return this.service.create(body);
    }

    // PUT /orders/:id
    @Put(':id')
    update(@Param('id', ParseIntPipe) id: number, @Body() body: any) {
        return this.service.update(id, body);
    }

    // DELETE /orders/:id
    @Delete(':id')
    remove(@Param('id', ParseIntPipe) id: number) {
        return this.service.remove(id);
    }
}
