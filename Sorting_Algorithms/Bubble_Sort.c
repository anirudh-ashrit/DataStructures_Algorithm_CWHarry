#include <stdio.h>
#include <stdlib.h>

void print(int a[], int l) {
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
}

void swap(int arr[], int a, int b) {
    int temp;

    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        printf("\nCurrent pass number is: %d", i+1);
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1])
                swap(a, j, j+1);
        }
    }
}

void adaptiveBubbleSort(int a[], int n) {
    
    int isSorted = 0;
    for(int i = 0; i < n-1; i++) {
        isSorted = 1;
        printf("\nCurrent pass number is: %d", i+1);
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                swap(a, j, j+1);
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}

void main() {
    int A[] = {1, 3, 2, 4, 6, 5};
    int len = sizeof(A)/sizeof(A[0]);

    print(A, len);
    // bubbleSort(A, len);
    adaptiveBubbleSort(A, len);
    printf("\nAfter Sorting\n");
    print(A, len);
}