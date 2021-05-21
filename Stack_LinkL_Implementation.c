#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define PART2

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

bool isEmpty(struct node *top) {
    if(top == NULL)
        return true;
    else
        return false;
}

bool isFull() {
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        return true;
    else
        return false;
}

#ifdef PART1
void push(struct node **top, int value) {

    if(isFull())
        printf("Stack is Full, cannot push new element\n");
    else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = *top;
        (*top) = newNode;
    }
}

int pop(struct node **top) {
    if(isEmpty(*top))
        printf("Stack empty, cannot pop the element\n");
    else {
        struct node *del = *top;
        int num;
        (*top) = (*top)->next;
        num = (del)->data;
        free(del);
        return num;
    }
}

void print(struct node *ptr) {
    
    while(ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
 
    push(&top, 1);
    push(&top, 3);
    push(&top, 5);
    push(&top, 7);
    push(&top, 11);
    print(top);
    printf("Popped element is %d\n", pop(&top));
    printf("Popped element is %d\n", pop(&top));
    printf("Popped element is %d\n", pop(&top));
    print(top);

    return 0;
}
#endif

#ifdef PART2
void push(int value) {

    if(isFull())
        printf("Stack is Full, cannot push new element\n");
    else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
}

int pop() {
    if(isEmpty(top))
        printf("Stack empty, cannot pop the element\n");
    else {
        struct node *del = top;
        int num;
        top = top->next;
        num = (del)->data;
        free(del);
        return num;
    }
}

void peek(int pos) {
    struct node *ptr = top;

    for(int i = 0; (i < pos-1 && ptr != NULL); i++)
        ptr = ptr->next;
    if(ptr != NULL)
        printf("Element at position %d is %d\n", pos, ptr->data);
    else
        printf("Invalid position\n");
}

void stackTop() {
    printf("The element at top of stack is: %d\n", top->data);
}

void stackBottom() {
    struct node *ptr = top;
    while(ptr->next != NULL)
        ptr = ptr->next;
    printf("The element at bottom of stack is: %d\n", ptr->data);
}

void print(struct node *ptr) {
    
    while(ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    
    int element;

    push(1);
    push(3);
    push(5);
    push(7);
    push(11);
    // print(top);
    // element = pop(top);
    // printf("Popped element is %d\n", element);
    // element = pop(top);
    // printf("Popped element is %d\n", element);
    // element = pop(top);
    // printf("Popped element is %d\n", element);
    // print(top);
    // peek(2);
    // peek(4);
    // peek(1);
    stackTop();
    stackBottom();

    return 0;
}
#endif