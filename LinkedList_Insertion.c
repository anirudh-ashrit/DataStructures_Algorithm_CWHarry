#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr) {
    while(ptr != NULL){
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Inserting at the Beginning
void insertNodeAtFirst(struct Node **head, int value) {
    
    struct Node *extra = (struct Node *)malloc(sizeof(struct Node));

    extra->data = value;
    extra->next = *head;
    *head = extra;
}

// Inserting at the given index or between
void insertNodeAtIndex(struct Node *head, int value, int pos) {
    
    struct Node *extra = (struct Node *)malloc(sizeof(struct Node));
    struct Node *index = head;
    int i = 0;

    while(i != pos-1) {
        index = index->next;
        i++;
    }

    extra->data = value;
    extra->next = index->next;
    index->next = extra;  
}

// Inserting at end
void insertAtEnd(struct Node *head, int value) {
    struct Node *extra = (struct Node *) malloc(sizeof(struct Node));
    struct Node *end = head;
    
    while(end->next != NULL)
        end = end->next;
    
    extra->data = value;
    extra->next = NULL;
    end->next = extra;
}

// Insert after a given Node
void insertAfterNode(struct Node *refNode, int value) {
    struct Node *extra = (struct Node *) malloc(sizeof(struct Node));

    extra->data = value;
    extra->next = refNode->next;
    refNode->next = extra;
}

void main() {
    
    struct Node *head, *second, *third, *fourth, *insert_n;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = fourth;

    third->data = 15;
    third->next = NULL;

    fourth->data = 17;
    fourth->next = third;

    Traversal(head);
    printf("After Instertion at Beginning\n");
     insertNodeAtFirst(&head, 5);
    //insertNodeAtIndex(head, 5, 1);
    //insertAtEnd(head, 19);
    //insertAfterNode(second, 13);
    Traversal(head);
}