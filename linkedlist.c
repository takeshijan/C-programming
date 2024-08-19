#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void print(){
    Node *p = head;
    while (p!= NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void insert_begin(int data){
    Node *l = (Node *)malloc(sizeof(Node));
    l->data = data;
    l->next = head;
    head = l;
}

void insert_end(int data){
    Node *l = (Node *)malloc(sizeof(Node));
    l->data = data;
    if(head == NULL){
        head = l;
    }
    else {
        Node *linkedlist = head;
        while (linkedlist->next != NULL) {
            linkedlist = linkedlist->next;
        }
        linkedlist->next = l;
    }
}

void insert_after(Node *list,int data){
    if(list == NULL){
        printf("not NULL");
        exit(0);
    }
    Node *l = (Node *)malloc(sizeof(Node));
    l->data = data;
    l->next = list->next;
    list->next = l;
}

void delete_begin(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    Node *current = head;
    head = head->next;
    free(current);
}

void delete_end(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node *lastnode = current->next;
    current->next = NULL;
    free(lastnode);
}

int main() {


    insert_end(12);
    insert_begin(99);
    insert_begin(2010201); 
    insert_begin(21021);

    delete_end();
    delete_begin();

    print();


    Node *current = head;
    Node *next_list;
    while (current !=NULL) {
        next_list = current->next;
        free(current);
        current = next_list;
    }
    head = NULL;
    
    return 0;
}
