#include <stdio.h>
#define MAX 100
void print1(int*, int);
int main(){
    int one[]={0, 1, 2, 3, 4};
    print1(one, 5);
    return 0;
}

void print1(int *ptr, int a) {
    for (int i=0;i<a;i++) {
        printf("The address is %8p and the value is %2d\n", ptr+i, *(ptr+i));
    }
    return;
}