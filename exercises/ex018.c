#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100
#define INVALID_KEY -1

typedef struct {
    int key;
} element;
element stack[MAX_STACK_SIZE];
int top=-1;

void push(element);
element pop();
void stackFull();
element stackEmpty();

int main(){
    int i=0;
    element e;

    for(i=0;i<15;i++){
        e.key=i;
        push(e);
        printf("key %d pushed into the stack.\n", e.key);
    }

    for (i=0;i<5;i++){
        e=pop();
        printf("key %d popped out from the stack.\n", e.key);
    }
    return 0;
}

void push(element item){
    if (top>=MAX_STACK_SIZE-1) stackFull();
    else stack[++top]=item;
    return;
}

element pop(){
    if (top==-1) return stackEmpty();
    else return stack[top--];
}

void stackFull(){
    fprintf(stderr, "Stack is full, cannot add element.\n");
    exit(EXIT_FAILURE);
}

element stackEmpty(){
    element e;
    e.key=INVALID_KEY;
    return e;
}