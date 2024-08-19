#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void print(){
    Node *link = head;
    while (link !=NULL) {
        printf("%d ",link->data);
        link = link->next;
    }
    printf("\n");
}

void insert_begin(int data){
    Node *link = (Node *)malloc(sizeof(Node));
    link -> data = data;
    link -> next = head;
    head = link;
}

void insert_end(int data){
    Node *link = (Node *)malloc(sizeof(Node));
    link -> data = data;
    link -> next = NULL;
    if(head == NULL){
        head = link;
    }
    else {
        Node *linkedlist = head;

        while (linkedlist->next != NULL) {
            linkedlist = linkedlist->next;
        }

        linkedlist->next = link;
    }
}

int main(){

    insert_end(20);
    insert_begin(0);
    insert_end(100);
    print();

    while (head != NULL) {
        Node *cur = head;
        head = head->next;
        free(cur);
    }

    return 0;
}
