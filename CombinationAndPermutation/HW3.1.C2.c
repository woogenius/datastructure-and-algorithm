//
//  HW3.1.C2
//  WooGenius
//  2013.10.14
//


#include <stdio.h>

int horner(int* array, int x, int howmany);

int main(void)
{
	int intArray[3] = {1, 2, 3};
	int x, answer;
    
	printf("input x = ");
	scanf("%d",&x);  // to get the x
    
    answer = horner(intArray, x, 3);
    
    printf("%dx^2+%dx+%d = %d\n", intArray[0], intArray[1], intArray[2], answer);
    
	return 0;
}

int horner(int* array, int x, int howmany)
{
	int answer=0;
    
	if(howmany-1==0)
		return array[0];
	else
		howmany--;
    
    answer = horner(array, x, howmany)*x+array[howmany];
    
    return answer;
}
