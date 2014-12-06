//
//  HW10.C1_1
//  WooGenius
//  13.12.7
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct heap {
    int size;
    int capacity;
    int *element;
} heap_t;

heap_t* allocMaxHeapWithCapacity(int capacity);
void freeMaxHeap(heap_t* heap);
void printHeap(heap_t *heap);
heap_t* makeSampleMaxHeap(int size);
int test_makeSampleMaxHeap(void);
int isMaxHeap(heap_t *heap);
void maxHeapify(heap_t *heap, int pos);
int test_maxHeapify(void);
int heapMaxExtract(heap_t *heap, int *maxValue);
int test_heapMaxExtract(void);
int heapInsert(heap_t *heap, int key);
int test_heapInsert(void);
void buildHeap(heap_t *heap);
int test_buildHeap(void);
void heapSort(int *arr, int length);
int test_heapSort(void);
void printArr(int *arr, int size);
int isSorted(int *arr, int size);

int main(void) {
    printf("Practice 2 : Test makeSampleMaxHeap\n");
    test_makeSampleMaxHeap();
    printf("\n");
    
    printf("Practice 3 : Test maxHeapify\n");
    test_maxHeapify();
    printf("\n");
    
    printf("Practice 4 : Test heapMaxExtract\n");
    test_heapMaxExtract();
    printf("\n");
    
    printf("Practice 5 : Test heapInsert\n");
    test_heapInsert();
    printf("\n");
    
    printf("Practice 6 : Test buildHeap\n");
    test_buildHeap();
    printf("\n");
    
    printf("Practice 7 : Test heapSort\n");
    test_heapSort();
    printf("\n");
    
    return 0;
}

heap_t* allocMaxHeapWithCapacity(int capacity) {
    heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
    int *arr = (int*)malloc(sizeof(int)*(capacity+1));
    
    heap->capacity = capacity;
    heap->element = arr;
    
    return heap;
}

void freeMaxHeap(heap_t* heap) {
    if (!heap || !heap->element) return;
    
    free(heap->element);
    free(heap);
}

void printHeap(heap_t *heap) {
    int i;
    for (i=1; i<=heap->size; i++) {
        printf("%2d ", heap->element[i]);
    }
    printf("\n");
}

heap_t* makeSampleMaxHeap(int size) {
    int i;
    heap_t *heap;
    heap = allocMaxHeapWithCapacity(64);
    heap->size = size;
    
    for (i=1; i<=size; i++) {
        heap->element[i] = size-i+1;
    }
    
    return heap;
}

int test_makeSampleMaxHeap(void) {
    heap_t *heap = makeSampleMaxHeap(12);
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    heap->element[1] = 1;
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    freeMaxHeap(heap);
    
    return 1;
}

int isMaxHeap(heap_t *heap) {
    int i;
    
    for (i=heap->size; i>=2; i--) {
        if (heap->element[i]>heap->element[i/2]) {
            return 0;
        }
    }
    
    return 1;
}

void maxHeapify(heap_t *heap, int pos) {
    int left = pos*2;
    int right = pos*2+1;
    int largest, temp;
    
    if (left<=heap->size && heap->element[left]>heap->element[pos])
        largest = left;
    else largest = pos;

    if (right<=heap->size && heap->element[right]>heap->element[largest])
        largest = right;
    
    if (largest != pos) {
        temp = heap->element[largest];
        heap->element[largest] = heap->element[pos];
        heap->element[pos] = temp;
        maxHeapify(heap, largest);
    }
}

int test_maxHeapify(void) {
    heap_t *heap = makeSampleMaxHeap(12);
    heap->element[1] = 1;
    
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    maxHeapify(heap, 1);
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    freeMaxHeap(heap);
    
    return 1;
}

int heapMaxExtract(heap_t *heap, int *maxValue) {
    if (!heap || heap->size==0) return 0;
    *maxValue = heap->element[1];
    
    heap->element[1] = heap->element[heap->size];
    heap->size--;
    
    maxHeapify(heap, 1);
    
    return 1;
}

int test_heapMaxExtract(void) {
    heap_t *heap = makeSampleMaxHeap(12);
    int maxValue;
    int boolean = heapMaxExtract(heap, &maxValue);

    while (boolean) {
        printf("Return : %d  Heap Max : %2d\n", boolean, maxValue);
        boolean = heapMaxExtract(heap, &maxValue);
    }

    freeMaxHeap(heap);
    
    return 1;
}

int heapInsert(heap_t *heap, int key) {
    int pos, temp;
    if (!heap || heap->size==heap->capacity) return 0;
    
    heap->size++;
    pos = heap->size;
    heap->element[pos] = key;
    
    while(pos>1 && heap->element[pos]>heap->element[pos/2]) {
        temp = heap->element[pos];
        heap->element[pos] = heap->element[pos/2];
        heap->element[pos/2] = temp;
        pos = pos/2;
    }
    
    return 1;
}

int test_heapInsert(void) {
    int i;
    heap_t *heap = allocMaxHeapWithCapacity(32);
    heap->size = 0;
    
    for (i=0; i<16; i++) {
        heapInsert(heap, i);
    }
    
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    freeMaxHeap(heap);
    
    return 1;
}

void buildHeap(heap_t *heap) {
    int i;
    if (!heap || heap->size==0) return;
    
    for (i=heap->size/2; i>0; i--) {
        maxHeapify(heap, i);
    }
}

int test_buildHeap(void) {
    int i;
    heap_t *heap= allocMaxHeapWithCapacity(32);
    heap->size = 32;
    
    srand((unsigned int)time(NULL));
    for (i=1; i<33; i++)
        heap->element[i] = rand()%100;
    
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    buildHeap(heap);
    printHeap(heap);
    if (isMaxHeap(heap)) printf("Valid Max Heap\n");
    else printf("Invalid Max Heap\n");
    
    freeMaxHeap(heap);
    
    return 1;
}

void heapSort(int *arr, int length) {
    int i, temp;
    heap_t heap;
    heap.element = arr-1;
    heap.size = length;
    
    buildHeap(&heap);
    for (i=length; i>1; i--) {
        temp = heap.element[1];
        heap.element[1] = heap.element[i];
        heap.element[i] = temp;
        
        heap.size--;
        
        maxHeapify(&heap, 1);
    }
}

int test_heapSort(void) {
    int i, j;
    int* arr;
    
    for (i=1; i<21; i++) {
        arr = (int*)malloc(sizeof(int)*i);
        
        srand((unsigned int)time(NULL)+i);
        for (j=0; j<i; j++)
            arr[j] = rand()%100;
        
        printf("%d Element Array\n", i);
        
        printArr(arr, i);
        if (isSorted(arr, i)) printf("Sorted Array\n");
        else printf("Not Sorted Array\n");
        
        heapSort(arr, i);
        
        printArr(arr, i);
        if (isSorted(arr, i)) printf("Sorted Array\n");
        else printf("Not Sorted Array\n");
        
        printf("\n");
        
        free(arr);
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
