
#include <stdio.h>
#include <stdlib.h>
#include "def.h"

static	node_t **nodeStack;
static	int		top;
static	int		capacity;

/*
 함수명: createStack
 매개변수: 초기 capacity
 기능: 주어진 capcity의 크기로 stack 생성
 return 값: 성공하면 0, 실패하면 -1
 */
static int	createStack(int initialCapacity)
{
	nodeStack = (node_t**)malloc(sizeof(node_t*)*initialCapacity);
    
	if(!nodeStack) return 0; // 스택 생성 실패
    
	capacity = initialCapacity;
	top = -1;
    
	return 1;
}

/*
 함수명: freeStack
 매개변수: 없음
 기능: stack에 사용된 메모리를 해제
 */
static void	freeStack()
{
	free(nodeStack);
}

/*
 함수명: stackExtension
 매개변수: 없음
 기능: stack에 저장할 수 있는 용량을 두 배로 늘림
 return 값: 없음
 */
static void	stackExtension(void)
{
	nodeStack = (node_t**)realloc(nodeStack, sizeof(node_t*) * 2 * capacity);
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
static void	push(node_t *node)
{
	if(isFull()) stackExtension();
    
	nodeStack[++top] = node;
}

/*
 함수명: pop
 매개변수: 없음
 기능: stack의 맨 위 원소를 제거하고 반납함
 return 값: 제거된 원소
 */
static node_t* pop()
{
	if(top < 0) return '\0';
    
	return nodeStack[top--];
}

static node_t* peek()
{
	if(top < 0) return '\0';
    
	return nodeStack[top];
}
