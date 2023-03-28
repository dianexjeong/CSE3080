#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS 1001
int main(){
    int number;
    int sorted[MAX_NUMBERS]={0};
    int unsorted[MAX_NUMBERS]={0};
    int index=0, x=0, y=0;
    while(1){
        printf("Enter a number (0 to quit): ");
        scanf("%d", &number);
        if (number==0) break;
        unsorted[index]=number;
        sorted[index]=number;
        if (index>0) {
                for (x=0;x<index;x++) {
                    for (y=0;y<index-x;y++) {
                        if (sorted[y]>sorted[y+1]) {
                            int tmp1=sorted[y];
                            int tmp2=sorted[y+1];
                            sorted[y]=tmp2;
                            sorted[y+1]=tmp1;
                        }
                    }
                }
            }
        
        int i=0;
        printf("unsorted: ");
        for (i=0; i<=index; i++) {
            printf("%d ", unsorted[i]);
        }
        printf("\n");
        i=0;
        printf("sorted: ");
        for (i=0; i<=index; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
        index+=1;
    }
    return 0;
}
