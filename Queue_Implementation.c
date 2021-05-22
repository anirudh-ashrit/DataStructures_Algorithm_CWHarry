#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue {
    int size, *arr ,r, f; 
};

#define PART2

#ifdef PART1
bool isFull(struct queue *qu) {
    struct queue *check = qu;
    if(check->r == check->size -1)
        return true;
    else
        return false;
}

bool isEmpty(struct queue *qu) {
    struct queue *check = qu;
    if(check->r == check->f)
        return true;
    else
        return false;
}

int enqueue(struct queue *qu, int value) {
    
    struct queue *add = qu;

    if(isFull(add))
        printf("Queue is full, cannot add element\n");
    else {
        add->r++;
        add->arr[add->r] = value;
        printf("Element added in queue is: %d\n", add->arr[add->r]);
    }
    return add->r;
}

int dequeue(struct queue *qu) {
    
    struct queue *rm = qu;

    if(isEmpty(rm))
        printf("Queue is empty, cannot remove element\n");
    else {
        rm->f++;
        return rm->arr[rm->f];
    }
}

void print(struct queue *qu) {
    
    struct queue *pr = qu;
    int i = pr->f+1;
    while(i != pr->r + 1) {
        printf("Element in queue is: %d\n", pr->arr[i]);
        i++;
    }
}

int main() {
    
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    print(&q);
    printf("Removed element is: %d\n", dequeue(&q));
}
#endif

#ifdef PART2

struct queue *q;

bool isFull() {
    struct queue *check = q;
    if(check->r == check->size -1)
        return true;
    else
        return false;
}

bool isEmpty() {
    struct queue *check = q;
    if(check->r == check->f)
        return true;
    else
        return false;
}

int enqueue(int value) {
    
    struct queue *add = q;

    if(isFull())
        printf("Queue is full, cannot add element\n");
    else {
        add->r++;
        add->arr[add->r] = value;
        printf("Element added in queue is: %d\n", add->arr[add->r]);
    }

    //printf("check %d", q->r);
    return add->r;
}

int dequeue() {
    
    struct queue *rm = q;

    if(isEmpty(rm))
        printf("Queue is empty, cannot remove element\n");
    else {
        rm->f++;
        return rm->arr[rm->f];
    }
}

void print() {
    
    struct queue *pr = q;
    int i = pr->f+1;
    while(i != pr->r + 1) {
        printf("Element in queue is: %d\n", pr->arr[i]);
        i++;
    }
}

int main() {
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("after");
    print(q);
    printf("Removed element is: %d\n", dequeue(q));

    return 0;
}
#endif