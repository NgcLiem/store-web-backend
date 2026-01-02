import {
    Body,
    Controller,
    Get,
    Param,
    ParseIntPipe,
    Patch,
    Query,
} from '@nestjs/common';
import { UsersService } from './users.service';
import { UpdateUserStatusDto } from './dto/update-user-status.dto';

@Controller('users')
export class UsersController {
    constructor(private readonly service: UsersService) {}

    // @Get()
    // getAll() {
    //     return this.service.findAll();
    // }

    @Get()
    findAll(@Query('q') q: string) {
        return this.service.findAll(q);
    }

    @Get(':id')
    getOne(@Param('id', ParseIntPipe) id: number) {
        return this.service.findOne(id);
    }

    @Patch(':id')
    updateStatus(
        @Param('id', ParseIntPipe) id: number,
        @Body() body: UpdateUserStatusDto,
    ) {
        return this.service.updateStatus(id, body.status);
    }
}
