#include<stdio.h>

void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int insertElement(int arr[], int elem, int size, int len, int pos) {
    if(pos >= len)
        return size;
    
    if(arr[pos] == NULL) {
        arr[pos] = elem;
        size += 1;
        return size;
    }

    for(int i = size-1; i >= pos; i--)
        arr[i+1] = arr[i];

    arr[pos] = elem;
    size += 1;
    return size;
}

int unsortedInsertion(int arr[], int elem, int size, int len, int pos) {
    if(pos >= len)
        return size;
    
    if(arr[pos] == NULL) {
        arr[pos] = elem;
        size += 1;
        return size;
    }

    int temp;
    temp = arr[pos];
    arr[pos] = elem;
    arr[size] = temp;
    size += 1;
    return size;
}

void main() {
    int array[10] = {2,4,7,9};
    int size_1 = 4, len = 10, size_2 = 4;

    displayArray(array, size_1);
    size_1 = insertElement(array, 5, size_1, len, 2);
    printf("\n");
    displayArray(array, size_1);
    size_2 = unsortedInsertion(array, 5,size_2, len, 2);
    printf("\n");
    displayArray(array, size_2);
}