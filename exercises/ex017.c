#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int pmatch(char*, char*);
void fail(char*);

int failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

int main(){
    int i=0;
    int index=0;
    strcpy(string, "ababcabcabababdabaabaabacabaababaaabaabaacaaba");
    strcpy(pat, "abaababaaaba");
    fail(pat);
    for (i=0;i<strlen(pat);i++){
        printf("%3d", failure[i]);
    }
    printf("\n");
    index=pmatch(string, pat);
    printf("index: %d\n", index);
    return 0;
}

void fail(char*p){
    failure[0]=-1;
    int i=0, j=0, n=strlen(pat);
    for(j=1;j<n;j++){
        i=failure[j-1];
        while ((p[j]!=pat[i+1]) && (i>=0)) i=failure[i];
        if (p[j]==p[i+1]) failure[j]=i+1;
        else failure[j]=-1;
    }
    return;
}

int pmatch(char*s, char*p){
    int i=0, j=0;
    int lens=strlen(s)-1;
    int lenp=strlen(p)-1;
    while (i<lens && j<lenp){
        if (s[i]==p[j]) {i++; j++;}
        else if (j==0) i++;
        else j=failure[j-1]+1;
    }
    return ((j==lenp) ? (i-lenp):1);

}