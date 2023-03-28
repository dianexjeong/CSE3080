#include <stdio.h>
#include <stdlib.h>
int main() {
    int *data;
    printf("How many integers do you want to generate? : ");
    int num;
    scanf("%d", &num);
    data=malloc(num*sizeof(int));
    for (int i=0;i<num;i++) {
        data[i]=rand();
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("How many integers do you want to generate additionally? : ");
    int addnum;
    scanf("%d", &addnum);
    data=realloc(data, (num+addnum)*sizeof(int));
    for (int i=num;i<num+addnum;i++) {
        data[i]=rand();
    }
    for (int i=0; i<num+addnum;i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    free(data);
    return 0;
}