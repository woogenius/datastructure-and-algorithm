//
//  HW3.1.C7
//  WooGenius
//  2013.10.14
//


#include <stdio.h>
#include <stdlib.h>

void powerset(char *set, int cnt, int curr, int end);
void printSetList();

char list[3] = {'a', 'b', 'c'};
char powersetList[8][4];        // 2차원 배열을 사용해서 setList를 표현

int main(void) {
    
    char set[4];
    powerset(set, 0, 0, 3);
    
    printSetList();
    return 0;
}

void powerset(char *set, int cnt, int curr, int end) {      // cnt : 몇 뎁스를 진행했나?, curr : 집합에서 현재의 위치(앞에 공백을 넣지 않기 위해), end : 끝나는 지점
    int count=0;
    static int rowCount=0;
    
    if (cnt==end) {
        set[curr+1] = '\0';
        while (set[count]) {
            powersetList[rowCount][count] = set[count];
            count++;
        }
        rowCount++;
    } else {
        powerset(set, cnt+1, curr, end);
        set[curr] = list[cnt];
        powerset(set, cnt+1, curr+1, end);
        set[curr] = '\0';
    }
}

void printSetList() {
    int row, col;
    for (row=0; row<8; row++) {
        col = 0;
        while (powersetList[row][col]) {
            printf("%c", powersetList[row][col]);
            col++;
        }
        printf("\n");
    }
}
