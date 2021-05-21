#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

void createNode(int value) {
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    newNode->data = value;
    newNode->next = head;
    if(head != NULL) {
        while(ptr->next != head)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    else 
        newNode->next = newNode;

    head = newNode;    
}

void Traversal(struct Node *head) {
    
    struct Node *ptr = head;
    do {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}

struct Node *insertAtStart(struct Node *head, int value) {
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = value;
    
    struct Node *p = head->next;
    while(p->next != head)
        p = p->next;
    
    p->next = temp;
    temp->next = head;

    return temp;
}

void insertAtIndex(struct Node *head, int value, int pos) {
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *ptr = head;
    int i = 0;

    while(i != pos-1) {
        ptr = ptr->next;
        i++;
    }

    insert->data = value;
    insert->next = ptr->next;
    ptr->next = insert;
}

void main( ) {

    head = NULL;

    createNode(3);
    createNode(5);
    createNode(7);
    createNode(11);
    createNode(13);
    createNode(15);

    Traversal(head);
    head = insertAtStart(head, 1);
    insertAtIndex(head, 10, 3);
    printf("Linked List after Insertion\n");
    Traversal(head);
}