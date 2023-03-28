#include <stdio.h>
#include <stdlib.h>
int** make2dArray (int, int);
int main() {
    int rows, cols;
    printf("How many rows in the array? : ");
    scanf("%d", &rows);
    printf("How many columns in the array? : ");
    scanf("%d", &cols);

    int ** array=make2dArray(rows, cols);
    int i=0, j=0;
    printf("The Array is :\n[ ");
    for (i=0;i<rows;i++) {
        for (j=0;j<cols;j++) {
            printf("%d ", array[i][j]);
        }
        if (i!=rows-1) printf("\n");
    }
    printf("]\n");
    return 0;
}

int** make2dArray(int r, int c) {
    int **x, i=0;
    x=calloc(r,sizeof(*x));
    for (i=0;i<r;i++) {
        x[i]=calloc(c,sizeof(int));
    }
    return x;
}