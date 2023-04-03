#include <stdio.h>
#include <stdlib.h>

struct listNode {
  char data;
  struct listNode *link;
};
struct listNode *first = NULL;

struct hoho {
  char data2;
};

int main(){
    struct listNode *newNode, *prevNode=NULL;
    struct listNode *currNode;
    char c;

    /*
    printf("size of struct: %lu\n", sizeof(newNode));
    printf("size of struct: %lu\n", sizeof(struct listNode));
    printf("size of struct: %lu\n", sizeof(struct hoho));
    return;
    */

    for (c='a'; c<='e'; c++){
       newNode=malloc(sizeof(*newNode));
       newNode->data=c;
       newNode->link=NULL;
       if(prevNode==NULL) first=newNode;
       else prevNode->link=newNode;
       prevNode=newNode;
    }

    currNode=first;
    while(currNode){
        printf("%c ", currNode->data);
        currNode=currNode->link;
    }
    printf("\n");

    currNode=first->link->link;
    printf("reading the 3rd element: %c\n", currNode->data);

    prevNode=first->link; //second element
    currNode=prevNode->link;
    prevNode->link=currNode->link;
    printf("deleting the 3rd element\n");
    free(currNode);

    currNode=first;
    while(currNode){
        printf("%c ", currNode->data);
        currNode=currNode->link;
    }
    printf("\n");

    newNode=malloc(sizeof(*newNode));
    newNode->data='f';
    newNode->link=NULL;
    prevNode=first->link;
    newNode->link=prevNode->link;
    prevNode->link=newNode;
    printf("inserting 'f' as the 3rd element\n");

    newNode=malloc(sizeof(*newNode));
    newNode->data='g';
    newNode->link=first;
    first=newNode;

    currNode=first;
    while(currNode){
        printf("%p ", currNode);
        currNode=currNode->link;
    }
    printf("\n");
}
