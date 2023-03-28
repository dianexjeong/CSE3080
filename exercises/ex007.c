#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    enum tagField {pitcher, hitter} role;
    union {
        int SO;
        int HR;
    } u;
} playerType;

typedef struct {
    char name[40];
    int age;
    float salary;
    date dob;
    playerType playerInfo;
} baseballPlayer;

void printPlayerInfo(baseballPlayer);

int main(){
    baseballPlayer person1, person2;
    strcpy(person1.name, "Hyun-Jin Ryu");
    person1.age=32;
    person1.salary=17900000.0;
    person1.dob.year=1987;
    person1.dob.month=3;
    person1.dob.day=25;
    person1.playerInfo.role=pitcher;
    person1.playerInfo.u.SO=163;

    strcpy(person2.name, "Shin-Soo Choo");
    person2.age=37;
    person2.salary=21000000.0;
    person2.dob.year=1982;
    person2.dob.month=7;
    person2.dob.day=13;
    person2.playerInfo.role=hitter;
    person2.playerInfo.u.HR=24;

    printPlayerInfo(person1);
    printPlayerInfo(person2);
    printf("HEllo");
    return 0;
}

void printPlayerInfo(baseballPlayer a) {
    printf("---------------------------------\n");
    printf("name : %s\n", a.name);
    printf("age : %d years old\n", a.age);
    printf("salary : $%.1f\n", a.salary);
    printf("dob: %4d/%2d/%2d\n", a.dob.year, a.dob.month, a.dob.day);
    if (a.playerInfo.role == pitcher) {
        printf("pitcher so : %d\n", a.playerInfo.u.SO);
    }
    else {
        printf("hitter hr : %d\n", a.playerInfo.u.HR);
    }
    printf("---------------------------------\n");
    return;
}