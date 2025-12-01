import {
    Controller,
    Post,
    UploadedFile,
    UseInterceptors,
} from '@nestjs/common';
import { FileInterceptor } from '@nestjs/platform-express';
import { diskStorage } from 'multer';
import { extname } from 'path';

@Controller('upload')
export class UploadController {
    @Post()
    @UseInterceptors(
        FileInterceptor('file', {
            storage: diskStorage({
                destination: './uploads', //  nơi lưu file
                filename: (req, file, callback) => {
                    //  tạo tên file duy nhất
                    const uniqueName =
                        Date.now() + '-' + Math.round(Math.random() * 1e9);
                    const fileExt = extname(file.originalname);
                    callback(null, uniqueName + fileExt);
                },
            }),
            limits: { fileSize: 5 * 1024 * 1024 }, // max 5MB
        }),
    )
    upload(@UploadedFile() file: any) {
        if (!file) {
            return { error: 'Không có file' };
        }

        //  URL ảnh trả về cho frontend
        const url = `http://localhost:3001/uploads/${file.filename}`;

        return { url };
    }
}
