//
//  HW3.1.C5
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

int Ackerman(int m, int n);

int main(void) {
    int m, n, result;
    
    printf("Input m, n : ");
    scanf("%d, %d", &m, &n);
    
    result = Ackerman(m, n);
    printf("Result is %d\n", result);
    
    return 0;
}

int Ackerman(int m, int n) {
    if (m==0) {
        return n+1;
    } else if (n==0) {
        return Ackerman(m-1, 1);
    } else {
        return Ackerman(m-1, Ackerman(m, n-1));
    }
}