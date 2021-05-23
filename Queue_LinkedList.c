#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front, *rear;

void print(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element in queue is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *enqueue(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
        printf("Heap has run out of memory\n");
    else {
        newNode->next = NULL;
        newNode->data = value;

        if (front == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;

        return front;
    }
}

int dequeue(struct Node *qu)
{
    if (front == NULL)
        printf("Queue is empty, cannot delete element\n");
    else {
        struct Node *del = qu;
        int num = qu->data;
        front = del->next;
        free(del);
        return num;
    }
}

int main() {
    
    front = enqueue(1);
    front = enqueue(2);
    front = enqueue(3);
    front = enqueue(4);
    print(front);
    printf("Removed element from queue: %d\n", dequeue(front));
    print(front);
    printf("Removed element from queue: %d\n", dequeue(front));
    printf("Removed element from queue: %d\n", dequeue(front));
    printf("Removed element from queue: %d\n", dequeue(front));
    printf("Removed element from queue: %d\n", dequeue(front));
}