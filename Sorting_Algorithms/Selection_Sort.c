#include <stdio.h>
#include <stdlib.h>

void print(int a[], int l) {
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
}

void selectionSort(int a[], int n) {
    int temp;

    for(int i = 0; i < n-1; i++) {
        int min = a[i];
        int k, j = i+1;
        while(j < n) {
            if(min > a[j]) {
                min = a[j];
                k = j;
            }
            j++;
        }
        temp = a[i];
        a[i] = min;
        a[k] = temp;
    }
}

void selectionShort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int temp, min = i, j = i+1;
        while(j < n) {
            if(a[min] > a[j]) {
                min = j;
            }
            j++;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void main() {
    int A[] = {8, 0, 15, 17, 1, 2};
    int len = sizeof(A)/sizeof(A[0]);

    print(A, len);
    selectionShort(A, len);
    printf("\nAfter Sorting\n");
    print(A, len);
}