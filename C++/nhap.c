#include <stdio.h>
void printarray(int a[], int n);

int main() {
    // int a[] = {3, 7, 5, 2, 4};
    // int n = 5, i, j , temp;
    // for (i = 0; i < n; i++)
    // {
    //     for(j = 0; j < a[i]; j++)
    //         printf("*");
    //     printf("\n");
    // }
    // for (i = 0; i < n - 1; i++)
    //     for (int j = i + 1; j < n; j++)
    //         if (a[i] > a[j]) {
    //             temp = a[i];
    //             a[i] = a[j];
    //             a[j] = temp;
    //         }
    // for (i = 0; i < n; i++){
    //     for(j = 0; j < a[i]; j++)
    //         printf("*");
        
    //     printf("\n");
    // }    
    // return 0;

    int a[] = {3,7,5,2,4};
    int i , *p, n =5;
    p = a;
    printarray(a,n);
    (*p)++;
    printarray(a,n);
    p+=2;
    (*p) +=2;
    printarray(a,n);
    p +=2;
    (*p) +=2;
    printarray(a,n);
    return 0;
}

void printarray(int a[], int n){
    int i;
    for (i =0; i<n; i++)
        printf("%d", a[i]);
    printf("\n");    
}
