#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMatrix(int**, int, int);
void transpose(int**, int, int);

int main(){
    int i=0, j=0;
    int **matrix;
    matrix=malloc(6*sizeof(*matrix));
    for(i=0;i<6;i++) {
        matrix[i]=malloc(6*sizeof(**matrix));
        for(j=0;j<6;j++) {
            matrix[i][j]=0;
        }
    }

    matrix[0][0] = 15;
    matrix[0][3] = 22;
    matrix[0][5] = -15;
    matrix[1][1] = 11;
    matrix[1][2] = 3;
    matrix[2][3] = -6;
    matrix[4][0] = 91;
    matrix[5][2] = 28;

    printMatrix(matrix, 6, 6);
    transpose(matrix, 6, 6);
    printMatrix(matrix, 6, 6);

    for(i=0;i<6;i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void printMatrix(int** matrix, int row, int col) {
    int i=0, j=0;
    for (i=0;i<row;i++){
        for (j=0;j<col;j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void transpose(int** matrix, int row, int col) {
    int i=0, j=0, temp=0;
    for (i=0;i<row;i++) {
        for (j=i+1;j<col;j++) {
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    return;
}