#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(){
    char string1[MAX]="amobile", *p1=string1;
    char string2[MAX]="uto", *p2=string2;
    char tmp[MAX]={0};
    strncpy(tmp, string1, 1);
    strcat(tmp, string2);
    strcat(tmp, string1+1);

    printf("%s\n", tmp);
    return 0;

}