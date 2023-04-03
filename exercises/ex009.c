#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TERMS 100
#define COMPARE(x, y) (x<y ? -1:(x>y ? 1:0))

typedef struct {
    int coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];

void polynomial_add(int, int, int, int, int*, int*);
void polynomial_print(int, int);
void attach(int, int);
int avail=0; 

int main(){
    int starta=0, finisha=0;
    int startb=0, finishb=0;
    int startc=0, finishc=0;

    starta=avail;
    terms[avail].expon=1000; terms[avail].coef=2;
    avail++;
    terms[avail].expon=0; terms[avail].coef=1;
    finisha=avail;
    avail++;

    startb=avail;
    terms[avail].expon=4; terms[avail].coef=1;
    avail++;
    terms[avail].expon=3; terms[avail].coef=10;
    avail++;
    terms[avail].expon=2; terms[avail].coef=3;
    avail++;
    terms[avail].expon=0; terms[avail].coef=1;
    finishb=avail;
    avail++;

    polynomial_add(starta, finisha, startb, finishb, &startc, &finishc);

    printf("Polynomial A\n");
    polynomial_print(starta, finisha);
    printf("Polynomial B\n");
    polynomial_print(startb, finishb);
    printf("Polynomial A+B\n");
    polynomial_print(startc, finishc);

    return 0;
}

void polynomial_add(int starta, int finisha, int startb, int finishb, int* startc, int* finishc) {
    *startc=avail;
    int c=0;
    while ((starta<=finisha)&&(startb>=finishb)) {
        switch(COMPARE(terms[starta].coef, terms[startb].coef)) {
            case -1:
                attach(terms[startb].expon, terms[startb].coef);
                startb++;
                break;
            case 0:
                c=terms[starta].coef+terms[startb].coef;
                if(c) attach(terms[starta].expon, c);
                starta++; startb++;
                break;
            case 1:
                attach(terms[starta].expon, terms[startb].expon);
                starta++;
                break;
        }

    }
    for (;starta<=finisha;starta++) 
        attach(terms[starta].expon, terms[starta].coef);
    for (;startb<=finishb;startb++)
        attach(terms[startb].expon, terms[startb].coef);
    *finishc=avail-1;
    return;
}

void attach(int exponent, int coefficient) {
    if(avail>=MAX_TERMS) {
        fprintf(stderr, "too many terms in the polynomial"); exit(1);
    }
    terms[avail].coef=coefficient; 
    terms[avail++].expon=exponent;
    return;
}

void polynomial_print(int start, int finish) {
    int i=0;
    for (i=start;i<=finish;i++) {
        if (i==start) {
            printf("%dx^%d", terms[i].coef, terms[i].expon);
        }
        else printf("+%dx^%d", terms[i].coef, terms[i].expon);
    }
    printf("\n");
    return;
}