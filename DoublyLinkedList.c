#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int key;
    struct Node *prev;
    struct Node *next;
} Node;


Node *head = NULL;
Node *last = NULL;

int is_empty(){
    return head == NULL;
}

void print(){
    Node *p = head;
    while (p!=NULL) {
        printf("%d : %d\n",p->key,p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(int key,int data){
    Node *linker = (Node *)malloc(sizeof(Node));
    if(linker == NULL){
        perror("Failed to allocate");
        exit(EXIT_FAILURE);
    }
    linker-> key = key;
    linker-> data = data;
    linker-> next = head;
    linker-> prev = NULL;

    if(is_empty()){
        last = linker;
    }
    else {
        head->prev = linker;
    }

    head = linker;
}

void free_list(){
    Node *current = head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    head = NULL;
    last = NULL;

}

int main() {
    insert(12, 13);
    insert(14, 15);
    insert(16, 17);
    print();
    free_list();
    return 0;
}
