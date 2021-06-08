////////////////////
//
//
//  Not Adaptive
//  O(n2)
//
//
////////////////////

#include <stdio.h>
#include <stdlib.h>

void print(int a[], int l) {
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
}

void insertionSort(int a[], int n) {
    int val;

    for(int i = 1; i < n; i++) {
        val = a[i];
        int j = i-1;
        while(j >=0 && a[j] < val){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    } 
}

void main() {
    int A[] = {6, 5, 4, 3, 2, 1};
    int len = sizeof(A)/sizeof(A[0]);

    print(A, len);
    insertionSort(A, len);
    printf("\nAfter Sorting\n");
    print(A, len);
}