//
//  HW4.2.C1~3
//  WooGenius
//  13.10.29
//


#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int rid;
    int cid;
    int value;
}term_t;

void transpose(term_t a[], term_t b[]);
void fastTranspose(term_t a[], term_t b[]);
void fastTransposeWithOneArray(term_t a[], term_t b[]);
int vectorInnerProduct(term_t a[], int startOfA, int endOfA,
                       term_t b[], int startOfB, int endOfB);
int findEndIdxWithEqualRowIdx(term_t a[], int startIdx);
term_t* multiplicationByBlock(term_t a[], term_t b[]);
void setSparseMatrix(term_t a[]);
void setSparseMatrix2(term_t a[]);
void printMatrix(term_t a[]);
void initArray(int a[], int size, int num);


int main(void) {
    term_t a[9];
    term_t b[9];
    term_t* c;
    setSparseMatrix(a);
    
    // HW4.2.C1
    printf("Transpose\n");
    printf("Source\n");
    printMatrix(a);
    printf("Result\n");
    transpose(a, b);
    printMatrix(b);
    printf("\n");
    
    // HW4.2.C1
    printf("Fast Transpose\n");
    printf("Source\n");
    printMatrix(a);
    printf("Result\n");
    fastTranspose(a, b);
    printMatrix(b);
    printf("\n");
    
    // HW4.2.C3
    printf("Fast Transpose With One Array\n");
    printf("Source\n");
    printMatrix(a);
    printf("Result\n");
    fastTransposeWithOneArray(a, b);
    printMatrix(b);
    printf("\n");

    // HW4.2.C2
    printf("Multiplication By Block\n");
    setSparseMatrix2(b);
    printf("Matrix A\n");
    printMatrix(a);
    printf("Matrix B\n");
    printMatrix(b);
    printf("A X B\n");
    c = multiplicationByBlock(a, b);
    printMatrix(c);
    printf("\n");
    
    free(c);
    
    return 0;
}

// HW4.2.C1
void transpose(term_t a[], term_t b[]) {
    int size;
    int acid;       // for searching a's col
    int aid, bid;
    
    // init Matrix B
    b[0].rid = a[0].cid;
    b[0].cid = a[0].rid;
    b[0].value = a[0].value;
    
    // size of matrix
    size = a[0].value;
    
    if (size>0) {
        bid = 1;
        for (acid=0; acid<a[0].cid; acid++) {
            for (aid=1; aid<=size; aid++) {
                if (a[aid].cid == acid) {
                    b[bid].rid = a[aid].cid;
                    b[bid].cid = a[aid].rid;
                    b[bid].value = a[aid].value;
                    bid++;
                }
            }
        }
    } else {
        printf("All Zero Matrix");
    }
}

// HW4.2.C1
void fastTranspose(term_t a[], term_t b[]) {
    int size, colSize = a[0].cid, i, j;
    int rowTerms[colSize];
    int startingPos[colSize];
    
    // init all the element for 0
    initArray(rowTerms, colSize, 0);
    
    // set size of matrix
    size = a[0].value;
    
    // init Matrix B
    b[0].rid = a[0].cid;
    b[0].cid = a[0].rid;
    b[0].value = a[0].value;
    
    if (size==0) {
        printf("All Zero Matrix");
        return;
    }
    
    // for rowTerms Array
    for (i=1; i<=size; i++) {
        rowTerms[a[i].cid]++;
    }
    
    // for startingPos Array
    startingPos[0] = 1;
    for (i=1; i<colSize; i++) {
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    }
    
    for (i=1; i<=size; i++) {
        j = startingPos[a[i].cid]++;
        b[j].rid = a[i].cid;
        b[j].cid = a[i].rid;
        b[j].value = a[i].value;
    }
}

// HW4.1.C3
void fastTransposeWithOneArray(term_t a[], term_t b[]) {
    int size, colSize = a[0].cid, i, j;
    int startingPos[colSize];   // use startingPos only
    
    // init all the element for 1
    initArray(startingPos, colSize, 1);
    
    // set size of matrix
    size = a[0].value;
    
    // init Matrix B
    b[0].rid = a[0].cid;
    b[0].cid = a[0].rid;
    b[0].value = a[0].value;
    
    // error case
    if (size==0) {
        printf("All Zero Matrix");
        return;
    }
    
    // HW4.1.C3
    // 배열에서 cid값의 다음부터 마지막까지 1을 더함
    for (i=1; i<=size; i++) {
        for (j=a[i].cid+1; j<colSize; j++) {
            startingPos[j]++;
        }
    }
    
    for (i=1; i<=size; i++) {
        j = startingPos[a[i].cid]++;
        b[j].rid = a[i].cid;
        b[j].cid = a[i].rid;
        b[j].value = a[i].value;
    }
}

void initArray(int a[], int size, int num) {
    int i;
    for (i=0; i<size; i++) {
        a[i] = num;
    }
}

// HW4.2.C2
int findEndIdxWithEqualRowIdx(term_t a[], int startIdx) {
    int endIdx = startIdx;
    
    while ((endIdx+1) <= a[0].value &&
           a[endIdx+1].rid == a[startIdx].rid) {
        endIdx++;
    }
    
    return endIdx;
}

// HW4.2.C2
int vectorInnerProduct(term_t a[], int startOfA, int endOfA,
                       term_t b[], int startOfB, int endOfB) {
    int value = 0;
    int aidx, bidx;
    
    aidx = startOfA;
    bidx = startOfB;
    
    while (aidx <= endOfA && bidx <= endOfB) {
        if (a[aidx].cid == b[bidx].cid) {
            value += a[aidx].value * b[bidx].value;
            aidx++;
            bidx++;
        } else if (a[aidx].cid < b[bidx].cid) aidx++;
        else bidx++;
    }
    
    return value;
}

// HW4.2.C2
term_t* multiplicationByBlock(term_t a[], term_t b[]) {
    // a x b = c
    term_t* c = (term_t *)malloc(sizeof(term_t));
    term_t b_trans[b[0].value+1];
    int startIdxOfA, startIdxOfBT, endIdxOfA, endIdxOfBT, innerProductValue, pid;

    // transpose matrixB
    fastTranspose(b, b_trans);
    
    // error case
    if (a[0].cid != b[0].rid) {
        printf("Invalid Multiplication");
        return c;
    }
    
    // init matrix c
    c[0].rid = a[0].rid;
    c[0].cid = b[0].cid;
    c[0].value = 0;
    
    startIdxOfA = 1;
    do {
        endIdxOfA = findEndIdxWithEqualRowIdx(a, startIdxOfA);
        startIdxOfBT = 1;
        do {
            endIdxOfBT = findEndIdxWithEqualRowIdx(b_trans, startIdxOfBT);
            innerProductValue = vectorInnerProduct(a, startIdxOfA, endIdxOfA,
                                                   b_trans, startIdxOfBT, endIdxOfBT);
            
            if (innerProductValue != 0) {
                pid = ++c[0].value;
                c = (term_t *)realloc(c, sizeof(term_t)*(pid+1));   // realloc the size of c
                c[pid].rid = a[startIdxOfA].rid;
                c[pid].cid = b_trans[startIdxOfBT].rid;
                c[pid].value = innerProductValue;
            }
            
            startIdxOfBT = endIdxOfBT + 1;
        } while (startIdxOfBT <= b_trans[0].value);
        startIdxOfA = endIdxOfA + 1;
    } while (startIdxOfA <= a[0].value);
    
    return c;
}

void setSparseMatrix(term_t a[]) {
    a[0].rid=6; a[0].cid=6; a[0].value=8;
    a[1].rid=0; a[1].cid=0; a[1].value=15;
    a[2].rid=0; a[2].cid=3; a[2].value=22;
    a[3].rid=0; a[3].cid=5; a[3].value=-15;
    a[4].rid=1; a[4].cid=1; a[4].value=11;
    a[5].rid=1; a[5].cid=2; a[5].value=3;
    a[6].rid=2; a[6].cid=3; a[6].value=-6;
    a[7].rid=4; a[7].cid=0; a[7].value=91;
    a[8].rid=5; a[8].cid=2; a[8].value=28;
}

void setSparseMatrix2(term_t a[]) {
    a[0].rid=6; a[0].cid=6; a[0].value=8;
    a[1].rid=0; a[1].cid=0; a[1].value=15;
    a[2].rid=0; a[2].cid=4; a[2].value=91;
    a[3].rid=1; a[3].cid=1; a[3].value=11;
    a[4].rid=2; a[4].cid=1; a[4].value=3;
    a[5].rid=2; a[5].cid=5; a[5].value=28;
    a[6].rid=3; a[6].cid=0; a[6].value=22;
    a[7].rid=3; a[7].cid=2; a[7].value=-6;
    a[8].rid=5; a[8].cid=0; a[8].value=-15;
}

void printMatrix(term_t a[]) {
    int i;
    int size = a[0].value+1;
    
    printf("rid cid value\n");
    for (i=0; i<size; i++) {
        printf(" %d   %d   %4d\n", a[i].rid, a[i].cid, a[i].value);
    }
    printf("\n");
}