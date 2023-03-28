#define MAXS 10000000
#define MAXP 3000
char string[MAXS] = {0};
char pattern[MAXP] = {0};
int listcount[MAXS] = {0};
#include <stdio.h>
#include <string.h>
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

    int i=0, j=0, count=0;
    int strl=strlen(string)-1, patl=strlen(pattern)-1;
    int lasts=strl-1, lastp=patl-1;
    int start=0, endmatch=lastp;
    for (i=0; endmatch<=lasts; start++, endmatch++) {
        if((pattern[0]==string[start])&&(pattern[lastp]==string[endmatch]))
            for (j=0; j<=lastp; j++){
                if (j==lastp) {
		    listcount[count]=start;
                    count+=1;
                    break;
                }
                else if(string[start+j]==pattern[j])
                    continue;
                else break;

            }
	
    }
    FILE *result;
    result=fopen("result_naive.txt", "w");
    fprintf(result, "%d\n", count);
    for (int a=0; a<count; a++) {
	    fprintf(result, "%d ", listcount[a]);
  	    if (a==count-1)
	        printf("\n");
    }
    fclose(str_f);
    fclose(pat_f);
    fclose(result);
    return 0;
}


