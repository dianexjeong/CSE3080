#include<stdio.h>
#include<stdlib.h>

int NUM_MOVES=0;

void towerOfHanoi(int, char, char, char);

int main(){
    int n=10;
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("total number of moves: %d\n", NUM_MOVES);
    return 0;
}

void towerOfHanoi(int disk, char from, char to, char aux){
    if (disk==1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        NUM_MOVES++;
        return;
    }
    towerOfHanoi(disk-1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", disk, from, to);
    NUM_MOVES++;
    towerOfHanoi(disk-1, aux, to, from);
    return;
}