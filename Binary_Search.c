#include<stdio.h>

int binarySearch(int arr[], int size, int elem){

    int start, endd, mid;

    start = 0;
    endd = size-1;
    

    while(start <= endd) {

        mid = (start + ((endd-start)/2));

        if(arr[mid] == elem){
            return mid;
        }
    
        if(arr[mid] < elem)
            start = mid+1;
        else
            endd = mid-1;
    }
    return 0;
}

void main() {

    int array[] = {10,15,18,23,39,46,51,69,77,82,93,104};
    int size = sizeof(array)/sizeof(int);
    int elem = 104, pos;

    pos = binarySearch(array, size, elem);
    if(pos >= 0)
        printf("The element %d has been found at position %d", elem, pos+1);
    else
        printf("Element %d not found", elem);
}