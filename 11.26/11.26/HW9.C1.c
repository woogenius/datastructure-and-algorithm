//
//  HW9.C1
//  WooGenius
//  13.11.25
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeSampleArrayInIncreasingOrder(int num);
int* makeSampleArrayInDecreasingOrder(int num);
int* makeSampleArray(int num);
int* makeSampleArrayWithSameValue(int num, int key);
void insertionSort(int *arr, int length);
void mergeSort(int *arr, int *bufferArr, int begin, int last);
void merge (int *arr, int *bufferArr, int firstBegin, int firstLast, int secondLast);
void copyBlockForMergeSort(int *fromBegin, int *fromEnd, int *toBegin);
int isSorted(int *arr, int num);
void testIsSorted(int *arr, int num);

int main(void)
{
    int *arr;
    int *bufferArr = (int*)malloc(sizeof(int)*100);
    
    // Insertion Sort
    printf("Insertion Sort\n");
    arr = makeSampleArrayInIncreasingOrder(0);
    insertionSort(arr, 0);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(1);
    insertionSort(arr, 1);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(2);
    insertionSort(arr, 2);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(3);
    insertionSort(arr, 3);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayInDecreasingOrder(0);
    insertionSort(arr, 0);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(1);
    insertionSort(arr, 1);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(2);
    insertionSort(arr, 2);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(3);
    insertionSort(arr, 3);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArray(0);
    insertionSort(arr, 0);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArray(1);
    insertionSort(arr, 1);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArray(2);
    insertionSort(arr, 2);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArray(3);
    insertionSort(arr, 3);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayWithSameValue(0, 1);
    insertionSort(arr, 0);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayWithSameValue(1, 1);
    insertionSort(arr, 1);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayWithSameValue(2, 1);
    insertionSort(arr, 2);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayWithSameValue(3, 1);
    insertionSort(arr, 3);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayInIncreasingOrder(10);
    insertionSort(arr, 10);
    testIsSorted(arr, 10);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(10);
    insertionSort(arr, 10);
    testIsSorted(arr, 10);
    free(arr);
    arr = makeSampleArray(20);
    insertionSort(arr, 20);
    testIsSorted(arr, 20);
    free(arr);
    arr = makeSampleArrayWithSameValue(4, 1);
    insertionSort(arr, 4);
    testIsSorted(arr, 4);
    free(arr);
    arr = makeSampleArrayWithSameValue(6, 1);
    insertionSort(arr, 6);
    testIsSorted(arr, 6);
    free(arr);
    printf("\n");
    
    // Merge Sort
    printf("Merge Sort\n");
    arr = makeSampleArrayInIncreasingOrder(0);
    mergeSort(arr, bufferArr, 0, -1);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(1);
    mergeSort(arr, bufferArr, 0, 0);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(2);
    mergeSort(arr, bufferArr, 0, 1);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayInIncreasingOrder(3);
    mergeSort(arr, bufferArr, 0, 2);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayInDecreasingOrder(0);
    mergeSort(arr, bufferArr, 0, -1);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(1);
    mergeSort(arr, bufferArr, 0, 0);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(2);
    mergeSort(arr, bufferArr, 0, 1);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(3);
    mergeSort(arr, bufferArr, 0, 2);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArray(0);
    mergeSort(arr, bufferArr, 0, -1);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArray(1);
    mergeSort(arr, bufferArr, 0, 0);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArray(2);
    mergeSort(arr, bufferArr, 0, 1);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArray(3);
    mergeSort(arr, bufferArr, 0, 2);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayWithSameValue(0, 1);
    mergeSort(arr, bufferArr, 0, -1);
    testIsSorted(arr, 0);
    free(arr);
    arr = makeSampleArrayWithSameValue(1, 1);
    mergeSort(arr, bufferArr, 0, 0);
    testIsSorted(arr, 1);
    free(arr);
    arr = makeSampleArrayWithSameValue(2, 1);
    mergeSort(arr, bufferArr, 0, 1);
    testIsSorted(arr, 2);
    free(arr);
    arr = makeSampleArrayWithSameValue(3, 1);
    mergeSort(arr, bufferArr, 0, 2);
    testIsSorted(arr, 3);
    free(arr);
    printf("\n");
    
    arr = makeSampleArrayInIncreasingOrder(10);
    mergeSort(arr, bufferArr, 0, 9);
    testIsSorted(arr, 10);
    free(arr);
    arr = makeSampleArrayInDecreasingOrder(10);
    mergeSort(arr, bufferArr, 0, 9);
    testIsSorted(arr, 10);
    free(arr);
    arr = makeSampleArray(20);
    mergeSort(arr, bufferArr, 0, 19);
    testIsSorted(arr, 20);
    free(arr);
    arr = makeSampleArrayWithSameValue(4, 1);
    mergeSort(arr, bufferArr, 0, 3);
    testIsSorted(arr, 4);
    free(arr);
    arr = makeSampleArrayWithSameValue(6, 1);
    mergeSort(arr, bufferArr, 0, 5);
    testIsSorted(arr, 6);
    free(arr);
    printf("\n");
    
    free(bufferArr);
    
    return 0;
}

// Practice2 Case1
int* makeSampleArrayInIncreasingOrder(int num) {
    int i;
    int *arr = (int*)malloc(sizeof(int)*num);
    
    for (i=0; i<num; i++) {
        arr[i] = i;
//        printf("%d\n", arr[i]);
    }
    
    return arr;
}

// Practice2 Case2
int* makeSampleArrayInDecreasingOrder(int num) {
    int i;
    int j = num-1;
    int *arr = (int*)malloc(sizeof(int)*num);
    
    for (i=0; i<num; i++) {
        arr[i] = j--;
//        printf("%d\n", arr[i]);
    }
    
    return arr;
}

// Practice2 Case3
int* makeSampleArray(int num) {
    int i;
    int *arr = (int*)malloc(sizeof(int)*num);
    
    srand((unsigned)time(0));
    for (i=0; i<num; i++) {
        arr[i] = rand()%10000;
//        printf("%d\n", arr[i]);
    }
    
    return arr;
}

// Practice2 Case4
int* makeSampleArrayWithSameValue(int num, int key) {
    int i;
    int *arr = (int*)malloc(sizeof(int)*num);
    
    srand((unsigned)time(0));
    for (i=0; i<num; i++) {
        arr[i] = key;
//        printf("%d\n", arr[i]);
    }
    
    return arr;
}

// Practice 3
void insertionSort(int *arr, int length) {
    int i, j, key;
    
    // i가 2번째 원소부터 마지막 원소까지 순차적으로 탐색
    for (i=1; i<length; i++) {
        key = arr[i];
        // j가 i-1부터 0까지 순차적으로 탐색하며 key보다 큰 원소들을 뒤로 한칸씩 밈
        for (j=i-1; 0<=j && arr[j]>key; j--) {
            arr[j+1]=arr[j];
        }
        // 다 밀리고 빈 자리에 key를 저장
        arr[j+1] = key;
    }
}

// Practice 4
void mergeSort(int *arr, int *bufferArr, int begin, int last) {
    int middle;
    
    if (begin < last) {
        middle = begin + (last-begin)/2;
        mergeSort(arr, bufferArr, begin, middle);
        mergeSort(arr, bufferArr, middle+1, last);
        merge(arr, bufferArr, begin, middle, last);
    }
}

void merge (int *arr, int *bufferArr, int firstBegin, int firstLast, int secondLast) {
    int idx, arr1Idx, arr2Idx;
    
    copyBlockForMergeSort(arr+firstBegin, arr+secondLast, bufferArr+firstBegin);
    
    arr1Idx = firstBegin;
    arr2Idx = firstLast+1;
    
    for (idx=firstBegin; idx<=secondLast; idx++) {
        // arr1이 범위를 넘어갔을 때
        if(arr1Idx > firstLast)
            arr[idx] = bufferArr[arr2Idx++];
        // arr2이 범위를 넘어갔을 때
        else if(arr2Idx > secondLast)
            arr[idx] = bufferArr[arr1Idx++];
        // arr2가 클때
        else if(bufferArr[arr1Idx] < bufferArr[arr2Idx])
            arr[idx] = bufferArr[arr1Idx++];
        // arr1이 클때
        else
            arr[idx] = bufferArr[arr2Idx++];
    }
}

// arr에서 bufferArr에 값을 복사하는 함수
void copyBlockForMergeSort(int *fromBegin, int *fromEnd, int *toBegin) {
    while (fromBegin <= fromEnd) {
        *toBegin = *fromBegin;
        fromBegin++;
        toBegin++;
    }
}

int isSorted(int *arr, int num) {
    int i;
    
    for (i=0; i<num-1; i++) {
        if(arr[i+1] < arr[i]) return 0;
    }
    
    return 1;
}

void testIsSorted(int *arr, int num) {
    if (isSorted(arr, num)) {
        printf("SORTED\n");
    } else {
        printf("NOT SORTED\n");
    }
}