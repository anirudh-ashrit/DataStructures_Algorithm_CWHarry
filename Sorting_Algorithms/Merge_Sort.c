#include <stdio.h>
#include <stdlib.h>

void print(int a[], int l) {
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
}

void mergeSort(int a[], int mid, int low, int high) {
    int b[50], i, j, k;
    i = k = low;
    j = mid+1;

    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        }
        else {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i <= mid) {
        b[k] = a[i];
        i++; k++;
    }

    while(j <= high) {
        b[k] = a[j];
        j++; k++;
    }

    for(int i = low; i <= high; i++)
        a[i] = b[i];
}

void merge(int a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low+high)/2;
        merge(a, low, mid);
        merge(a, mid+1, high);
        mergeSort(a, mid, low, high);
    }
}

void main() {
    int A[] = {10, 3, 14, 42, 6, 5};
    int len_1 = sizeof(A)/sizeof(A[0]);

    print(A, len_1);
    merge(A, 0, len_1);
    printf("\nAfter Sorting\n");
    print(A, len_1);
}