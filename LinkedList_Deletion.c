#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

void Traversal(struct Node *ptr) {
    while(ptr != NULL){
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteAtStart(struct Node *head) {
    struct Node *del = head;
    head = head->next;
    free(del);
    return head;
}

void deteAtIndex(struct Node *head, int pos) {
    struct Node *del, *index;
    int i = 0;
    del = head;
    index = head->next;

    while(i != pos - 1) {
        del = del->next;
        index = index->next;
        i++;
    }

    del->next = index->next;
    free(index);
}

void deleteAtEnd(struct Node *head) {
    struct Node *del, *end;

    del = head;
    end = head->next;

    while(end->next != NULL) {
        del = del->next;
        end = end->next;
    }

    del->next = end->next;
    free(end);
}

void deleteByValue(struct Node *head, int value) {
    struct Node *prev = head;
    struct Node *curr = head->next;

    while(curr->next != NULL) {
        
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else {
            curr = curr->next;
            prev = prev->next;
        }
    }
}

void main() {
    
    struct Node *second, *third, *fourth, *insert_n;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 17;
    fourth->next = NULL;

    Traversal(head);
    //head = deleteAtStart(head);
    //deteAtIndex(head, 3);
    //deleteAtEnd(head);
    deleteByValue(head, 11);
    printf("\n\n");
    Traversal(head);
}