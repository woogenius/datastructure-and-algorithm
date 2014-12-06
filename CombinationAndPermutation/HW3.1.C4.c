//
//  HW3.1.C4
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

void ascendingPrint(int *numList, int curr, int end);
void swap(int *a, int *b);

int main(void) {
    int i, num;
    int numList[3];
    
    printf("input 3 numbers\n");
    
    for (i=0; i<3; i++) {
        scanf("%d", &num);
        numList[i] = num;
    }
    
    ascendingPrint(numList, 0, 3);
    
    return 0;
}

void ascendingPrint(int *numList, int curr, int end) {
    int i;
    
    if (curr==end) {
        for (i=0; i<end; i++) {
            printf("%d ", numList[i]);
        }
        printf("\n");
    } else {
        for (i=curr; i<end; i++) {
            if (numList[curr]>numList[i]) {
                swap(&numList[curr], &numList[i]);
            }
        }
        ascendingPrint(numList, curr+1, end);   // recursive point
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
