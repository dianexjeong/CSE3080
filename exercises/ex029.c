#include<stdio.h>
#include<stdlib.h>

#define IS_EMPTY(x) !x

struct list_node {
    char data;
    struct list_node *link;
};
typedef struct list_node* list_pointer;

void print_circular_list(list_pointer);
void insert_front(list_pointer*, list_pointer);

int main(){
    list_pointer last, a, b, c, d;
    a=(list_pointer)malloc(sizeof(struct list_node));
    b=(list_pointer)malloc(sizeof(struct list_node));
    c=(list_pointer)malloc(sizeof(struct list_node));
    a->data='A';
    b->data='B';
    c->data='C';
    a->link=b;
    b->link=c;
    c->link=a;
    last=c;

    print_circular_list(last);

    d=(list_pointer)malloc(sizeof(struct list_node));
    d->data='D';
    d->link=NULL;
    insert_front(&last, d);
    print_circular_list(last);

    return 0;
}

void print_circular_list(list_pointer last){
    list_pointer temp=last->link;
    while(1){
        printf("%c ", temp->data);
        if(temp==last) break;
        temp=temp->link;
    }
    printf("\n");

    return;
}

void insert_front(list_pointer *ptr, list_pointer node){
    if (IS_EMPTY(*ptr)) {
        *ptr=node;
        node->link=node;
    }
    else{
        node->link=(*ptr)->link;
        (*ptr)->link=node;
    }
    return;
}