#include "def.h"

#if CHAR_STACK_TEMPLATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static	char	*charStack;
static	int		top;
static	int		capacity;

/*
 함수명: createStack
 매개변수: 초기 capacity
 기능: 주어진 capcity의 크기로 stack 생성
 return 값: 성공하면 0, 실패하면 -1
 */
static int	createCharStack(int initialCapacity)
{
	charStack = (char *)malloc(sizeof(char)*initialCapacity);
    
	if(!charStack) return -1; // 스택 생성 실패
    
	capacity = initialCapacity;
	top = -1;
    
	return 0;
}

/*
 함수명: freeStack
 매개변수: 없음
 기능: stack에 사용된 메모리를 해제
 */
static void	freeStack()
{
	free(charStack);
}

/*
 함수명: stackExtension
 매개변수: 없음
 기능: stack에 저장할 수 있는 용량을 두 배로 늘림
 return 값: 없음
 */
static void	stackExtension(void)
{
	charStack = (char *)realloc(charStack, sizeof(char) * 2 * capacity);
	capacity *= 2;
}

/*
 함수명: isEmpty
 매개변수: 없음
 기능: stack에 원소가 한 개도 없는지 확인
 return 값: stack이 empty이면 1, 아니면 0
 */
static int	isEmpty()
{
	if(top < 0)
		return 1;
	else
		return 0;
}

/*
 함수명: isFull
 매개변수: 없음
 기능: stack이 꽉 차 있는지 확인
 return 값: 꽉 찼으면 1, 아니면 0
 */
static int	isFull()
{
	if(top >= capacity - 1)
		return 1;
	else
		return 0;
}

/*
 함수명: push
 매개변수
 ch: char type
 기능: ch을 stack의 top에 추가
 return 값: 없음
 */
static void	push(char ch)
{
	// full이면 stack 용량 확장
	// top에 문자 추가
    
    if (isFull()) {
        stackExtension();
    } else {
        charStack[++top] = ch;
    }
}

/*
 함수명: pop
 매개변수: 없음
 기능: stack의 맨 위 원소를 제거하고 반납함
 return 값: 제거된 원소
 */
static char pop()
{
	// empty이면NULL 문자를 return
	// empty가 아니면 top에 있는 문자 return
    
    if (isEmpty()) {
        return NULL;
    } else {
        return charStack[top--];
    }
}

/*
 함수명: testStringReverse
 매개변수: 없음
 기능: string reverse
 예) "ABCD"를 "DCBA"의 순서로 출력
 comments
 초기에 용량 1인 stack 생성
 10개 원소를 하나씩 push
 stack이 empty가 될때까지 pop
 */
void	testStringReverse()
{
	char	str[] = "ABCD";
	int		i;
	
	if(createCharStack(1) != 0) return;
    
	for(i=0; i < strlen(str); i++)
		push(str[i]);
    
	while(!isEmpty()) printf("%c", pop());
	printf("\n");
    
	freeStack();
}

#endif // CHAR_STACK_TEMPLATE