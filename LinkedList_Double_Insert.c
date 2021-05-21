#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

#define PART2

#ifdef PART1
struct Node *last = NULL;

void Traversal(struct Node *ptr_1) {

    while(ptr_1 != NULL){
        printf("Element %d\n", ptr_1->data);
        ptr_1 = ptr_1->next;
    }
}

void reverseTraverse() {
    struct Node *ptr_2 = last;
    while(ptr_2 != NULL){
        printf("Element %d\n", ptr_2->data);
        ptr_2 = ptr_2->prev;
    }
}

// Inserting at the Beginning
void insertNodeAtFirst(struct Node **head, int value) {
    
    struct Node *extra = (struct Node *)malloc(sizeof(struct Node));

    extra->data = value;
    if(head == NULL)
        last = extra;
    else
        (*head)->prev = extra;
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
    extra->prev = index->next->prev;
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
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 15;
    third->next = fourth;
    third->prev = second;

    fourth->data = 17;
    fourth->next = NULL;
    fourth->prev = third;

    // Traversal(head);
    // printf("\nAfter Instertion at Beginning\n");
    insertNodeAtFirst(&head, 5);
    // insertNodeAtIndex(head, 5, 2);
    // insertAtEnd(head, 19);
    // insertAfterNode(second, 13);
    Traversal(head);
    printf("\nReverse printing of elements\n\n");
    reverseTraverse();
    // printf("Node Data is: %d\n", second->data);
    // printf("Node Next is: %d\n", second->next->data);
    // printf("Node prev is: %d\n", second->prev->data);
}
#endif

#ifdef PART2

struct Node *head = NULL;
struct Node *tail = NULL;

void printForward() {
    struct Node *ptr = head;
    while(ptr!=NULL) {
        printf("Element is %d\n", ptr->data);
        ptr=ptr->next;
    }
}

void create_list(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
}

void insertAtFirst(int value) {
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
}

void insertAtEnd(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(int pos, int value) {
    
    struct Node *ptr = head;

    int i = 0;
    while(i != pos - 1){
        ptr = ptr->next;
        i++;
    }

    if(ptr->next == head->next)
        insertAtFirst(value);

    else if(ptr->next == tail->next)
        insertAtEnd(value);

    else {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        newNode->prev = ptr;
        ptr->next = newNode;
    }
}

int deleteAtFirst() {
    
    struct Node *del = head;
    int num;

    num = head->data;
    head = del->next;
    head->prev = NULL;
    free(del);
    printf("Returned Element: %d\n", num);
    return num;
}

int deleteAtLast() {
    
    struct Node *del = tail;
    int num;

    num = tail->data;
    tail = del->prev;
    tail->next = NULL;
    free(del);
    return num;
}

int deleteAtPosition(int pos) {
    
    struct Node *del = head;
    int num, i = 0;

    while(i != pos-1) {
        del = del->next;
        i++;
    }

    if(del->next == head->next)
        deleteAtFirst();

    else if(del->next == tail->next)
        deleteAtLast();

    else {
        num = del->data;
        del->prev->next = del->next;
        del->next->prev = del->prev;
        free(del);
        printf("Delete at pos %d\n", num);
        return num;
    }

}

int main() {
    for(int i = 1; i < 5; i++)
        create_list(i);
    printForward();
    insertAtFirst(0);
    insertAtEnd(5);
    insertAtPosition(1, 6);
    printf("\n");
    printForward();
    deleteAtFirst();
    deleteAtLast();
    deleteAtPosition(5);
    printf("\n");
    printForward();
}
#endif