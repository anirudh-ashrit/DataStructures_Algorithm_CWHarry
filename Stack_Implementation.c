#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size, top, *arr;
};

void push(struct stack *ptr, int val) {

    if(ptr->top == ptr->size - 1) 
        printf("Stack is full cannot push element inside\n");
    else {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr) {

    int num;

    if(ptr->top == -1) {
        printf("Stack is empty cannot pop any element\n");
        return -1;
    }

    num = ptr->arr[ptr->top];
    ptr->top = ptr->top - 1;
    return num;
}

void peek(struct stack *s, int i) {
    
    int arrPos = s->top-i + 1;
    if(arrPos < 0)
        printf("Invalid position\n");
    else {
        printf("The element at position %d is: %d\n", i, s->arr[arrPos]);
        peek(s, ++i);
    }
}

void printStack(struct stack *ptr) {
    for(int i = 0; i <= ptr->top; i++)
            printf("Element in stack at index %d is: %d\n", i, ptr->arr[i]);
}

void main() {

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    pop(s);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    printStack(s);
    pop(s);
    printf("\nAfter popping an element\n\n");
    push(s, 14);
    printStack(s);
    peek(s, 1);
}