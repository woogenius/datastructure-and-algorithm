//
//  HW3.1.C1
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

void comb(char *list, int curr, int end);

int main(void) {
    char list[3] = {'a', 'b', 'c'};
    
    comb(list, 0, 3);
    
    return 0;
}

void comb(char *list, int curr, int end) {      // curr : 현재 뎁스, end : 끝
    int i;
    char temp;
    
    if (curr==end) {
        for (i=0; i<end; i++) {
            if (list[i]) {
                printf("%c", list[i]);
            }
        }
        printf("\n");
    } else {
        temp = list[curr];
        list[curr] = '\0';
        comb(list, curr+1, end);
        list[curr] = temp;
        comb(list, curr+1, end);
    }

    
}
