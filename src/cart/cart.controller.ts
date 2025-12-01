import {
    Controller,
    Get,
    Query,
    Post,
    Body,
    Put,
    Param,
    ParseIntPipe,
    Delete,
} from '@nestjs/common';
import { CartService } from './cart.service';

@Controller('cart')
export class CartController {
    constructor(private readonly service: CartService) { }

    // GET /cart?user_id=3
    @Get()
    getUserCart(@Query('user_id') userId: string) {
        const user_id = Number(userId);
        return this.service.getUserCart(user_id);
    }

    // POST /cart
    @Post()
    addItem(@Body() body: any) {
        return this.service.addItem(body);
    }

    // PUT /cart/item/:id
    @Put('item/:id')
    updateItem(
        @Param('id', ParseIntPipe) id: number,
        @Body() body: any,
    ) {
        return this.service.updateItem(id, body);
    }

    // DELETE /cart/item/:id
    @Delete('item/:id')
    removeItem(@Param('id', ParseIntPipe) id: number) {
        return this.service.removeItem(id);
    }

    // DELETE /cart/clear?user_id=3
    @Delete('clear')
    clearUserCart(@Query('user_id') userId: string) {
        const user_id = Number(userId);
        return this.service.clearUserCart(user_id);
    }
}
