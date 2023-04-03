#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
void strnins(char*, char*, int);

int main(){
    char s[MAX_SIZE]="amobile";
    char t[MAX_SIZE]="uto";
    strnins(s, t, 1);
    printf("%s\n", s);
    return 0;
}

void strnins(char*a, char*b, int x){
    char string[MAX_SIZE]={'\0'};
    char *temp=string;
    if((x<0)||(x>strlen(a))){
        fprintf(stderr, "position is out of bounds.\n");
        exit(1);
    }
    if (!strlen(a)) strcpy(a, b);
    else if (strlen(b)){
        strncpy(temp, a, x);
        strcat(temp, b);
        strcat(temp, (a+x));
        strcpy(a, temp);
    }
    return;
}