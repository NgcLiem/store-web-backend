import {
    Controller,
    Get,
    Param,
    Query,
    Put,
    Patch,
    Delete,
    Body,
    UseGuards,
    ParseIntPipe,
    BadRequestException,
} from '@nestjs/common';
import { OrdersService } from './orders.service';
@Controller('staff/orders')
export class StaffOrdersController {
    constructor(private readonly ordersService: OrdersService) {}

    //  LIST: GET /staff/orders?status=&q=
    @Get()
    async list(@Query('status') status?: string, @Query('q') q?: string) {
        // staff xem tất cả đơn
        return this.ordersService.findAll({ status, q });
    }

    //  DETAIL: GET /staff/orders/:id
    @Get(':id')
    async detail(@Param('id', ParseIntPipe) id: number) {
        return this.ordersService.findOneWithItems(id);
    }

    //  UPDATE (FE gọi PUT /staff/orders/:id)
    @Put(':id')
    async update(@Param('id', ParseIntPipe) id: number, @Body() body: any) {
        // Nếu muốn staff cập nhật status:
        if (!body || !body.status) {
            throw new BadRequestException('Thiếu status');
        }
        return this.ordersService.update(id, { status: body.status });
    }

    @Patch(':id/status')
    async updateStatus(
        @Param('id', ParseIntPipe) id: number,
        @Body() body: { status: string },
    ) {
        if (!body?.status) throw new BadRequestException('Thiếu status');
        await this.ordersService.update(id, { status: body.status as any });
        // Return updated order with items
        return await this.ordersService.findOneWithItems(id);
    }

    //  DELETE: /staff/orders/:id
    @Delete(':id')
    async remove(@Param('id', ParseIntPipe) id: number) {
        return this.ordersService.remove(id);
    }
}
