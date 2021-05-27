#include <stdio.h>
#include <stdlib.h>

void print(int a[], int l) {
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int partition(int arr[], int lo, int hg) {
    int temp;
    int pivot = arr[lo];
    int i = lo+1;
    int j = hg;

    do {
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i < j);

    temp = arr[lo];
    arr[lo] = arr[j];
    arr[j] = temp;
    print(arr, 6);
    return j;
}

void quickSort(int a[], int low, int high) {
    
    int partitionIndex;
    
    if(low < high) {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex-1);
        quickSort(a, partitionIndex+1, high);
    }
}

void main() {
    int A[] = {1, 3, 2, 4, 6, 5};
    int len = sizeof(A)/sizeof(A[0]);

    print(A, len);
    quickSort(A, 0, len-1);
    printf("After Sorting\n");
    print(A, len);
}