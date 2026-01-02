export class CreateProductDto {
    name!: string;
    price!: number;
    description?: string;
    imageUrl?: string;
    categoryId?: number;
    stock?: number;
    brand?: string;
    [key: string]: any;
}
