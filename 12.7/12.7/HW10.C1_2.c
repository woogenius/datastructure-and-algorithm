//
//  HW10.C1_2
//  WooGenius
//  13.12.7
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int left, int right);
int test_partition(void);
void quicksort(int *arr, int left, int right);
int test_quicksort(void);
void printArr(int *arr, int size);
int isSorted(int *arr, int size);
int isPartitioned(int *arr, int pivot, int length);

int main(void) {
    printf("Practice 8 : Test partition\n");
    test_partition();
    printf("\n");
    
    printf("Practice 9 : Test quicksort\n");
    test_quicksort();
    printf("\n");
    
    return 0;
}

int partition(int *arr, int left, int right) {
    int i, j, temp;
    int pivotValue = arr[right];
    
    i = left-1;
    
    for (j=left; j<right; j++) {
        if (arr[j]<=pivotValue) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    
    temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    
    return i+1;
}

int test_partition(void) {
    int i, j, pivot;
    int *arr;
    
    for (i=1; i<33; i++) {
        arr = (int*)malloc(sizeof(int)*i);
        
        srand((unsigned int)time(NULL)+i);
        for (j=0; j<i; j++)
            arr[j] = rand()%100;
        
        printf("%d Element Array\n", i);
        printf("Before\n");
        printArr(arr, i);
        
        pivot = partition(arr, 0, i-1);
        
        printf("After : Pivot=%d, PivotValue=%d\n", pivot, arr[pivot]);
        printArr(arr, i);
        if (isPartitioned(arr, pivot, i)) printf("Partitioned Array\n");
        else printf("Not Partitioned Array\n");
        
        printf("\n");
        
        free(arr);
    }
    
    return 1;
}

void quicksort(int *arr, int left, int right) {
    int pivot;
    
    if (left<right) {
        pivot = partition(arr, left, right);
        quicksort(arr, left, pivot-1);
        quicksort(arr, pivot+1, right);
    }
}

int test_quicksort(void) {
    int i, j;
    int* arr;
    
    for (i=1; i<33; i++) {
        arr = (int*)malloc(sizeof(int)*i);
        
        srand((unsigned int)time(NULL)+i);
        for (j=0; j<i; j++)
            arr[j] = rand()%100;
        
        printf("%d Element Array\n", i);
        
        printArr(arr, i);
        if (isSorted(arr, i)) printf("Sorted Array\n");
        else printf("Not Sorted Array\n");
        
        quicksort(arr, 0, i-1);
        
        printArr(arr, i);
        if (isSorted(arr, i)) printf("Sorted Array\n");
        else printf("Not Sorted Array\n");
        
        printf("\n");
        
        free(arr);
    }
    
    return 1;
}

int isPartitioned(int *arr, int pivot, int length) {
    int i;
    
    for (i=0; i<pivot; i++) {
        if (arr[i]>arr[pivot])
            return 0;
    }
    
    for (i=pivot+1; i<length; i++) {
        if (arr[i]<=arr[pivot])
            return 0;
    }
    
    return 1;
}

void printArr(int *arr, int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

int isSorted(int *arr, int size) {
    int i;
    for (i=0; i<size-1; i++) {
        if (arr[i]>arr[i+1]) {
            return 0;
        }
    }
    
    return 1;
}
