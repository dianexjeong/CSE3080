#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

typedef struct node* listPointer;

void print_forward(listPointer);
void print_reverse(listPointer);
void insert(listPointer, listPointer);
void delete(listPointer, int);
listPointer first=NULL;

int main(int argc, char *argv[]){
    listPointer list, curr, new, del;
    /*creating a head node as list*/
    list=(listPointer)malloc(sizeof(struct node));
    list->data=-1;
    list->next=list;
    list->prev=list;

    curr=list;
    first=list;
    if (argc!=2){
        printf("usage: ./hw2 input_filename");
        return 1;
    }
    else {
        
        FILE *inputfile;
        inputfile=fopen(argv[1], "r");
        if (inputfile==NULL){
            printf("The input file does not exist.");
            return 2;
        }
        else {
            while(1){
                char* command=NULL;
                command=(char*)malloc(100*sizeof(char));
                fscanf(inputfile, "%s", command);
                if(strcmp(command, "INSERT")==0){
                    int i=0;
                    fscanf(inputfile, "%d", &i);
                    new=(listPointer)malloc(sizeof(struct node));
                    new->data=i;
                    new->next=NULL;
                    new->prev=NULL;
                    if(list->data==-1){
                        list->data=i;
                        free(new);
                    }
                    else if (curr->next==curr){
                        if((curr->data)!=(new->data)){
                            new->next=curr;
                            new->prev=curr;
                            curr->next=new;
                            curr->prev=new;
                            if((new->data)<(curr->data)) first=new; //is this possible?
                        }
                        else {
                            free(new);
                        }
                    }
                    else 
                    insert(first, new);
                }
                
                else if (strcmp(command, "DELETE")==0){
                    int del=0;
                    fscanf(inputfile, "%d", &del);
                    delete(first, del);
                }
                
                else if (strcmp(command, "ASCEND")==0){
                    print_forward(first);
                }
                else if (strcmp(command, "DESCEND")==0){
                    print_reverse(first);
                }
                free(command);
                if (feof(inputfile)) break;

            }
        }
    fclose(inputfile);
        
    }
    

    return 0;
}
void insert(listPointer list, listPointer new){
    listPointer curr;
    if ((new->data)<(list->data)){
        new->next=list;
        new->prev=list->prev;
        list->prev->next=new;
        list->prev=new;
        first=new;
        return;
    }
    else if ((new->data)>(list->prev->data)){
        new->next=list;
        new->prev=list->prev;
        list->prev->next=new;
        list->prev=new;
        return;
    }
    else{
        curr=list;
        while(1) {
            if((curr->data)==(new->data)){
                free(new);
                break;
            }
            else if (((curr->data)<(new->data))&&((new->data)<(curr->next->data))){
                new->next=curr->next;
                new->prev=curr;
                curr->next->prev=new;
                curr->next=new;
                break;
            }
            curr=curr->next;
            if(curr==list) break;
        }
        return;
    }
}

void delete(listPointer list, int del){
    listPointer curr, deleted;
    curr=list;
    while(1){
        if(del==(curr->data)){
            deleted=curr;
            if(del==(list->data)){
                deleted->prev->next=deleted->next;
                deleted->next->prev=deleted->prev;
                first=deleted->next;
                free(deleted);
                break;
            }
            else{
                deleted->next->prev=deleted->prev;
                deleted->prev->next=deleted->next;
                free(deleted);
                break;
            }
        }
        else curr=curr->next;

        if(curr==list) break;
    }
    return;
}

void print_forward(listPointer list){
    listPointer curr;
    FILE *outfile;

    outfile = fopen("hw2_result.txt", "a");
    if(list) {
        curr=list;
        while(1) {
            fprintf(outfile, "%d ", curr->data);
            printf("%d ", curr->data);
            curr=curr->next;
            if(curr==list) break;
        }
    }
    fprintf(outfile, "\n");
    printf("\n");
    fclose(outfile);
}

void print_reverse(listPointer list){

    listPointer curr;
    FILE *outfile;

    outfile=fopen("hw2_result.txt", "a");
    if(list) {
        curr=list->prev;

        while(curr!=list){
            fprintf(outfile, "%d ", curr->data);
            printf("%d ", curr->data);
            curr=curr->prev;
        }
        fprintf(outfile, "%d ", curr->data);
        printf("%d ", curr->data);
    }
    fprintf(outfile, "\n");
    printf("\n");
    fclose(outfile);
}

