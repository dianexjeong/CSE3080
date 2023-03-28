#include<stdio.h>
int main() {
    int i, j, *pi, *pj;
    pi=&i; pj=&j;
    *pi=100; *pj=200;
    *(pi+1)=300;
    printf("i: %d\n", i);
    printf("j: %d", j);
    return 0;
}