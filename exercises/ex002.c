#include <stdio.h>
#define MAX_SIZE 100
int sum(int[], int);
int input[MAX_SIZE], answer;
int i;
int main() {
    int number, count=0;
    while (1) {
        printf("Enter a number (0 to quit) : ");
        scanf("%d", &number);
        input[count]=number;
        count+=1;
        if (number==0) break;
    }
    int sumnum=sum(input, count);
    printf("The sum is %d.\n", sumnum);

    return 0;

}

int sum(int num[MAX_SIZE], int a) {
    int tempsum=0;
    for (int x=0;x<a;x++) {
        tempsum+=num[x];
    }
    return tempsum;
}