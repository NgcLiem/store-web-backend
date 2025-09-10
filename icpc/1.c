#include<stdio.h>

int main(){
    int row, column;

    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &column);
    int array[row][column];

    printf("Nhap phan tu cua mang 2 chieu: \n");
    for (int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("phan tu [%d][%d]: ", i, j);
            scanf("%d",&array[i][j]);
        }
    }

    printf("Xuat phan tu le cua mang 2 chieu: \n");
    for (int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(array[i][j] % 2 != 0){
                
                printf("%d",array[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}