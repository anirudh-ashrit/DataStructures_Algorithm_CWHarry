#define PART1

#ifdef PART1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue {
    int size, *arr ,r, f; 
};

struct queue *q;

bool isFull(struct queue *qu) {
    struct queue *check = qu;
    int ck = (check->r+1) % check->size;
    if(ck == qu->f)
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

struct queue *enqueue(struct queue *qu, int value) {
    
    struct queue *add = qu;

    if(isFull(add))
        printf("Queue is full, cannot add element\n");
    else {
        add->r = (add->r+1) % add->size;
        add->arr[add->r] = value;
        printf("Element added in queue is: %d\n", add->arr[add->r]);
    }
    return add;
}

int dequeue(struct queue *qu) {
    
    struct queue *rm = qu;

    if(isEmpty(rm))
        printf("Queue is empty, cannot remove element\n");
    else {
        rm->f = (rm->f+1) % rm->size;
        return rm->arr[rm->f];
    }
}

void print(struct queue *qu) {
    
    struct queue *pr = qu;
    int i = (pr->f+1) % pr->size;
    do {
        printf("Element in queue is: %d\n", pr->arr[i]);
        i = (i+1) % pr->size;
    } while(i != (pr->r+1)%pr->size);
}

int main() {
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    struct queue *pr;

    pr = enqueue(q, 1);
    pr = enqueue(q, 2);
    pr = enqueue(q, 3);
    pr = enqueue(q, 4);
    pr = enqueue(q, 5);
    pr = enqueue(q, 6);
    pr = enqueue(q, 7);
    print(pr);
    printf("Removed element is: %d\n", dequeue(q));
    printf("Removed element is: %d\n", dequeue(q));
    printf("Removed element is: %d\n", dequeue(q));

    return 0;
}
#endif

#ifdef PART2

#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}


int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }

    return 0;
}

#endif