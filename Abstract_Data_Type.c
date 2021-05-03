/*****
 * 
 * 
 * An abstract data type to create an array is written in C
 * 
 * 
******/

#include<stdio.h>

struct ADT
{
    int total_size, used_size;
    int *base_addr;
};

struct ADT marks;

void createArray(struct ADT *arr, int tSize, int uSize) {
    
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->base_addr = (int *)malloc(tSize * sizeof(int));
}

void getValues(struct ADT *arr) {

    for(int i = 0; i < arr->used_size; i++) {
        int n;
        printf("Enter the number: ");
        scanf("%d", &n);
        arr->base_addr[i] = n;
    }
}

void displayValues(struct ADT *arr) {

    for(int i = 0; i < arr->used_size; i++) {
        printf("The number at index %d is %d\n", i, arr->base_addr[i]);
    }
}

void main() {

    createArray(&marks, 10, 2);
    getValues(&marks);
    displayValues(&marks);
}