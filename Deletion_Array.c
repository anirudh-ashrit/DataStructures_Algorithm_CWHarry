#include<stdio.h>

void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int deleteElement(int arr[], int size, int len, int pos) {
    if((pos > len) || (pos < 0) || (arr[pos] == NULL))
        return size;
    
    if(pos == (size-1)) {
        arr[pos] = NULL;
        size -= 1;
        return size;
    }

    for(int i = pos; i < size-1; i++)
        arr[i] = arr[i+1];

    size -= 1;
    return size;
}

int unsortedDeletion(int arr[], int size, int len, int pos) {
    if(pos > len || pos < 0)
        return size;
    
    if(pos == (size-1)) {
        arr[pos] = NULL;
        return size -= 1;
    }
    
    arr[pos] = NULL;
    return size;
}

void main() {
    int array1[10] = {2,4,7,9};
    int size_1 = 4, len = 10, size_2 = 4;

    displayArray(array1, size_1);
    size_1 = deleteElement(array1, size_1, len, 1);
    printf("\n");
    displayArray(array1, size_1);
    int array2[10] = {2,4,7,9};
    size_2 = unsortedDeletion(array2, size_2, len, 1);
    printf("\n");
    displayArray(array2, size_2);
}