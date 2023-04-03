#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct {
    int key;
} element;

element queue[MAX_QUEUE_SIZE];
int rear=-1;
int front=-1;

void addq(element);
element deleteq();
void queueFull();
element queueEmpty();

int main(){
    int i=0;
    element e;
    for (i=0;i<8;i++){
        e.key=i;
        addq(e);
        printf("key %2d inserted into the queue.\nfront: %2d rear: %2d\n", e.key, front, rear);
    }
    for (i=0;i<8;i++){
        e=deleteq();
        printf("key %2d deleted from the queue. \nfront: %2d rear: %2d\n", e.key, front, rear);
    }
    for (i=8;i<16;i++){
        e.key=i;
        addq(e);
        printf("key %2d inserted into the queue.\nfront: %2d rear: %2d\n", e.key, front, rear);
    }
    return 0;
}

void addq(element e){
    if(rear==MAX_QUEUE_SIZE-1) queueFull();
    else queue[++rear]=e;
    return;
}

element deleteq(){
    if(front==rear) return queueEmpty();
    else return queue[++front];
}

void queueFull(){
    //fprintf(stderr, "No more space in the queue\n");
    //exit(1);

    if(front==-1){
        fprintf(stderr, "No more space in the queue\n");
        exit(1);
    }    
    else{
        int offset=front+1;
        int i=0;
        for(i=front+1;i<MAX_QUEUE_SIZE;i++){
            queue[i-offset]=queue[i];
        }
        front=front-offset;
        rear=rear-offset;
        printf("===== queue reorganized. \nfront: %2d rear: %2d\n", front, rear);
        
    }
}

element queueEmpty(){
    element e;
    e.key=INVALID_KEY;
    return e;
}

