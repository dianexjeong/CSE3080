#include <stdio.h>
int main(){
    int number[10]={10, 5, 6, 2, 1, 4, 8, 3, 7, 9};
    int n=10;
    int x=0, y=0;
    int tmp1, tmp2;

    for (x=0;x<n-1;x++) {
        for (y=0;y<n-x-1;y++) {
            if (number[y]>number[y+1]) {
                tmp1=number[y];
                tmp2=number[y+1];
                number[y]=tmp2;
                number[y+1]=tmp1;
            }
        }
    }

    for (int a=0;a<10;a++) {
        printf("%d ", number[a]);
    }
    printf("\n");
    return 0;
}