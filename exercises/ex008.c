#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DEGREE 101

typedef struct {
    int degree;
    int coef[MAX_DEGREE];
} polynomial;

polynomial polynomial_add(polynomial, polynomial);
void polynomial_print(polynomial);

int main(){
    int i;
    polynomial p1;  //p1=3x^2+2x+4
    polynomial p2;  //p2=x^4+10x^3+3x^2+1
    polynomial p3;  //the sum of the two

    p1.degree=-1; 
    p2.degree=-1;
    for (i=0;i<MAX_DEGREE;i++) {
        p1.coef[i]=0;
        p2.coef[i]=0;
    }
    p1.degree=2; p1.coef[2]=3; p1.coef[1]=2; p1.coef[0]=4;
    p2.degree=4; p2.coef[4]=1; p2.coef[3]=10; p2.coef[2]=3; p2.coef[0]=1;
    
    printf("Polynomial A\n");
    polynomial_print(p1);
    printf("Polynomial B\n");
    polynomial_print(p2);
    printf("Polynomial A+B\n");
    p3=polynomial_add(p1, p2);
    polynomial_print(p3);

    return 0;
}

void polynomial_print(polynomial a) {
    int i=0;
    for (i=a.degree;i>=0;i--) {
        if (i==0) printf("%d\n", a.coef[0]);
        else if (a.coef[i]!=0) {
            if (a.coef[i]==1) printf("x^%d+", i);
            else printf("%dx^%d+", a.coef[i], i);
        }
    }
    return;
}

polynomial polynomial_add(polynomial a, polynomial b) {
    polynomial sum;
    int max=a.degree, i=0;
    if (b.degree>a.degree) max=b.degree;
    sum.degree=max;
    for (i=max;i>=0;i--) {
        sum.coef[i]=a.coef[i]+b.coef[i];
    }
    return sum;
}