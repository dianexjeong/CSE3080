#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nfind(char*, char*);

int main(){
    char pat[]="wor";
    char str[]="hello world I am a student.";
    int index=nfind(str, pat);
    if (index==-1) printf("The pattern %s was not found in the string.\n", pat);
    else printf("The pattern %s was found at position %d in the string.\n", pat, index);

    return 0;
}

int nfind(char*a, char*b){
    int i=0, j=0;
    int start=0;
    int lasts=strlen(a)-2;
    int lastp=strlen(b)-2;
    int endmatch=lastp;
    int index=-1;
    for(i=0;endmatch<=lasts;endmatch++, start++){
        if ((b[0]==a[start])&&(b[lastp]==a[endmatch]))
            for (j=0;j<=lastp;j++){
                if(j==lastp) {
                    index=start;
                    break;
                }
                else if (a[start+j]==b[j]) continue;
                else break;
            }
    }
    return index;
}