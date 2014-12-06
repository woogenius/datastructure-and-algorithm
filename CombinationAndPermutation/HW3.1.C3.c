//
//  HW3.1.C3
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

void printBoolean(char *charList, int curr, int end);

int main(void)
{
	int howmany;
    char charList[4];
    
	printf("how many variables do you need? ");
	scanf("%d",&howmany);
    
    printBoolean(charList, 0, howmany);
    
	return 0;
}

void printBoolean(char *charList, int curr, int end) {
    int i;
    
    if (curr==end) {
        for (i=0; i<end; i++) {
            printf("%c", charList[i]);
        }
        printf("\n");
    } else {
        charList[curr] = 'T';
        printBoolean(charList, curr+1, end);
        charList[curr] = 'F';
        printBoolean(charList, curr+1, end);
    }
}