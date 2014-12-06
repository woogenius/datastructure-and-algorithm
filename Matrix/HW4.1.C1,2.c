//
//  HW4.1.C1,2
//  WooGenius
//  13.10.20
//


#include <stdio.h>
#include <stdlib.h>

// HW4.1.C1
int **make2dArray(int row, int col);
void set2dArray(int **arr, int row, int col);
void print2dArray(int **arr, int row, int col);
int **makeSetPrint2dArray(int row, int col);

// HW4.1.C2
int matrixSum(int **result, int **matrixA, int **matrixB, int rowNum, int colNum);
int matrixMulti(int **result,
                int **matrixA, int rowNumOfA, int colNumOfA,
                int **matrixB, int rowNumOfB, int colNumOfB);
int matrixTranspose(int **result, int **matrixA, int rowNum, int colNum);

int main(void) {
    int **matrixA;
    int **matrixB;
    int **result;
    
    // HW4.1.C1
    makeSetPrint2dArray(1, 1);
    makeSetPrint2dArray(1, 2);
    makeSetPrint2dArray(5, 5);
    makeSetPrint2dArray(6, 10);
    
    // HW4.1.C2
    printf("matrixA\n");
    matrixA = makeSetPrint2dArray(3, 3);
    printf("matrixB\n");
    matrixB = makeSetPrint2dArray(3, 3);
    result = make2dArray(3, 3);
    
    printf("Sum\n");
    matrixSum(result, matrixA, matrixB, 3, 3);
    print2dArray(result, 3, 3);
    
    printf("Multi\n");
    matrixMulti(result, matrixA, 3, 3, matrixB, 3, 3);
    print2dArray(result, 3, 3);
    
    printf("TransPose\n");
    matrixTranspose(result, matrixA, 3, 3);
    print2dArray(result, 3, 3);
    
    return 0;
}

// HW4.1.C1
int **makeSetPrint2dArray(int row, int col) {
    int **arr;
    
    arr = make2dArray(row, col);
    set2dArray(arr, row, col);
    print2dArray(arr, row, col);
    
    return arr;
}

int **make2dArray(int row, int col) {
    int **arr, i;
    
    arr = (int **)malloc(sizeof(int *)*row);
    
    for (i=0; i<col; i++) {
        arr[i] = (int *)malloc(sizeof(int)*col);
    }
    
    return arr;
}

void set2dArray(int **arr, int row, int col) {
    int rid, cid;
    
    for (rid=0; rid<row; rid++) {
        for (cid=0; cid<col; cid++) {
            arr[rid][cid] = (rid*row)+cid;
        }
    }
}

void print2dArray(int **arr, int row, int col) {
    int rid, cid;
    
    for (rid=0; rid<row; rid++) {
        for (cid=0; cid<col; cid++) {
            printf("%2d ", arr[rid][cid]);
        }
        printf("\n");
    }
    printf("\n");
}

// HW4.1.C2
int matrixSum(int **result, int **matrixA, int **matrixB, int rowNum, int colNum) {
    int rid, cid;
    
    for (rid=0; rid<rowNum; rid++) {
        for (cid=0; cid<colNum; cid++) {
            result[rid][cid] = matrixA[rid][cid] + matrixB[rid][cid];
        }
    }
    
    return 0;
}

int matrixMulti(int **result,
                int **matrixA, int rowNumOfA, int colNumOfA,
                int **matrixB, int rowNumOfB, int colNumOfB) {
    int rid, cid, pid;
    
    for (rid=0; rid<rowNumOfA; rid++) {
        for (cid=0; cid<colNumOfB; cid++) {
            result[rid][cid] = 0;
            for (pid=0; pid<colNumOfA; pid++) {
                result[rid][cid] += matrixA[rid][pid]*matrixB[pid][cid];
            }
        }
    }
    
    return 0;
}

int matrixTranspose(int **result, int **matrixA, int rowNum, int colNum) {
    int rid, cid;
    
    for (rid=0; rid<rowNum; rid++) {
        for (cid=0; cid<colNum; cid++) {
            result[cid][rid] = matrixA[rid][cid];
        }
    }
    
    return 0;
}