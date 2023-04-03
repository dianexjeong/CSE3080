#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
typedef struct {
    int month;
    int date;
    int year;
} date;
typedef struct {
    char name[10];
    int age;
    float salary;
    date dob;
} humanBeing;
int humans_equal(humanBeing, humanBeing);
int main(){
    humanBeing x, y;
    printf("Enter the name of person 1: ");
    scanf("%s", &x.name);
    printf("Enter the age of person 1: ");
    scanf("%d", &x.age);
    printf("Enter the salary of person 1 :");
    scanf("%f", &x.salary);
    printf("Enter the name of person 2: ");
    scanf("%s", &y.name);
    printf("Enter the age of person 2: ");
    scanf("%d", &y.age);
    printf("Enter the salary of person 2: ");
    scanf("%f", &y.salary);
    if (humans_equal(x, y)) {
        printf("Person 1 and Person 2 are equal\n");
    }
    else printf("Person 1 and Person 2 are not equal\n");

    return 0;
}

int humans_equal(humanBeing a, humanBeing b) {
    if (strcmp(a.name, b.name))
        return FALSE;
    if (a.age != b.age)
        return FALSE;
    if (a.salary != b.salary)
        return FALSE;
    else return TRUE;
}
