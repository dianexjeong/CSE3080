#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *link;
};
struct listNode *head;

int find(int);
int length();
void printList();

int main(){
    struct listNode *node, *prevNode=NULL;
    int i=0;

    for (i=10;i<=100;i+=10){
        node=malloc(sizeof(*node));
        node->data=i;
        node->link=NULL;
        if (prevNode==NULL) head=node;
        else prevNode->link=node;
        prevNode=node;
    }
    printList();
    printf("result of finding %d: %d\n", 30, find(30));
    printf("number of integers in this list: %d\n", length());

    return 0;
}

int find(int key){
    struct listNode *curr=head;
    int i=0;

    while(curr){
        if(curr->data==key) return i;
        i++;
        curr=curr->link;
    }
    return -1;
}

int length(){
    struct listNode *curr=head;
    int count=0;

    while(curr){
        count++;
        curr=curr->link;
    }
    return count;
}

void printList(){
    struct listNode* curr=head;
    int i=0;

    printf("printList: ");
    while (curr){
        printf("%d ", curr->data);
        curr=curr->link;
    }
    printf("\n");
}