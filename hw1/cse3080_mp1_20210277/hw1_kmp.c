#define MAXS 10000000
#define MAXP 3000
char string[MAXS] = {0};
char pattern[MAXP] = {0};
int listcount[MAXS] = {0};
int failure[MAXP] = {0};
#include <stdio.h>
#include <string.h>
void fail_function(char*);
int main(){
    FILE *str_f, *pat_f;
    str_f=fopen("string.txt", "r");
    pat_f=fopen("pattern.txt", "r");
    if ((str_f==NULL)||(pat_f==NULL)){
        printf("The string file does not exist.\n");
        return 1;
    }

    int a=0, b=0;
    fgets(string, MAXS, str_f);
    fgets(pattern, MAXP, pat_f);
    fail_function(pattern);
    
    int strl=strlen(string)-1, patl=strlen(pattern)-1;
    int i=0, j=0, count=0;
    while((i<strl)&&(j<=patl)){
        if (j==patl){
            i-=1; j-=1;
            listcount[count]=(i-j);
            count+=1;
            j=failure[j-1]+1;
            continue;
            }
        else if (string[i]==pattern[j]) {i++; j++;}
        else if ((string[i]!=pattern[j])&&(j==0)) i++;
        else j=failure[j-1]+1;
    }
    FILE *result;
    result=fopen("result_kmp.txt", "w");
    fprintf(result, "%d\n", count);
    for (int a=0; a<count; a++) {
        fprintf(result, "%d ", listcount[a]);
        if (a==count-1) printf("\n");
    }
    fclose(str_f);
    fclose(pat_f);
    fclose(result);

    return 0;
}

void fail_function(char *pat){
    int i=0, j=0;
    failure[0]=-1;
    for(j=1; j<strlen(pat); j++){
        i=failure[j-1];
        while((pat[j]!=pat[i+1])&&(i>=0))
            i=failure[i];
        if (pat[j]==pat[i+1])
            failure[j]=i+1;
        else failure[j]=-1;
    }
    return;
}
