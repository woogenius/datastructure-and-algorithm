//
//  HW3.1.C6
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

void hanoi(int howMany, char moveFrom, char toUse , char moveTo);

int main(void) {
	char a='a', b='b', c='c';
	int howMany;
    
	printf("How many board do you want to move?");  // to get the quantity of board
	scanf("%d",&howMany);
    
	hanoi(howMany, a, b, c);
    
	return 0;
}

void hanoi(int howMany, char moveFrom, char toUse, char moveTo) {
	if(howMany==1)
		printf("move 1st board from %c to %c\n", moveFrom, moveTo);
	else {
		hanoi(howMany-1, moveFrom, moveTo, toUse);
		printf("move %dth board from %c to %c\n", howMany, moveFrom, moveTo);
		hanoi(howMany-1, toUse, moveFrom, moveTo);
	}
}
