import { Module } from '@nestjs/common';
import { StaffController } from './staff.controller';
import { StaffService } from './staff.service';
import { DbModule } from '../db/db.module';

@Module({
  imports: [DbModule],
  controllers: [StaffController],
  providers: [StaffService],
})
export class StaffModule { }
