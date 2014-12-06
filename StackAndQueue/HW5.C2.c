#include "def.h"

#if QUEUE_TEMPLATE

#include <stdio.h>
#include <stdlib.h>

static	int	*queue;
static	int	capacity;
static	int	front; // 다음 번 처리/삭제할 대상의 직전 위치. 즉, (front + 1) % capacity에 있는 item을 삭제
static	int	rear; // 다음 번 대상을 저장할 위치의 직전 위치. 즉, (rear + 1) % capacity 자리에 item을 추가

void printQueue(void);

/*
 함수명: createQueue
 기능: queue를 생성함
 매개변수
 initialCapacity: 정수값으로 queue의 초기 용량을 지정함
 return 값: 생성에 성공하면 0, 실패하면 -1
 */
static int	createQueue(int	initialCapacity)
{
	queue = (int *)malloc(sizeof(int)*initialCapacity);
	
	if(!queue) return -1;
    
	capacity = initialCapacity;
	front = 0;
	rear = 0;
    
	return 0;
}

/*
 함수명: freeQueue
 기능: queue에 사용되고 있는 메모리를 해제
 매개변수: 없음
 return 값: 없음
 */
static void	freeQueue()
{
	free(queue);
}

/*
 함수명: isFull
 기능: queue가 꽉 찬 상태인지 여부 확인
 매개변수: 없음
 return 값: 꽉 차 있으면 1, 아니면 0.
 comments: 엄밀히 말하면 꽉 찬 상태에서 빈 자리가 1개가 남아 있으나
 이것을 사용하면 empty 상태와 구분이 되지 않아서
 1개 빈 자리가 있을 때를 full 상태로 처리함
 */
static int isFull()
{
	if((rear + 1) % capacity == front)
		return 1;
	else
		return 0;
}

/*
 함수명: isEmpty
 기능: queue가 비어 있는지 확인
 매개변수: 없음
 return 값: empty이면 1, 아니면 0
 */
static int	isEmpty()
{
	if(front == rear)
		return 1;
	else
		return 0;
}

/*
 함수명: copyBlock
 기능: [srcBegin, srcEnd)까지의 원소들을 dst에 복사
 매개변수
 srcBegin: 원래 배열의 시작 위치
 srcEnd: 복사할 배열의 마지막 원소 위치 + 1
 dst: 새롭게 저장할 배열
 */
void	copyBlock(int *srcBegin, int *srcEnd, int *dst)
{
    while (srcBegin < srcEnd) {
        *dst = *srcBegin
        dst++;
        srcBegin++;
    }
}

/*
 함수명: queueEntension
 기능: queue의 용량을 두 배로 늘림
 매개변수: 없음
 return 값: 없음
 */
static void	queueExtension(void)
{
	int	*newQueue;
	int	startPos;
    
	newQueue = (int *)malloc(sizeof(int)*2*capacity);
    
	if(!newQueue) return;
    
	startPos = (front + 1) % capacity;
    
	if(startPos < 2) {
        copyBlock(queue + startPos, queue + startPos + capacity - 1, newQueue);
    } else {
		copyBlock(queue + startPos, queue + capacity, newQueue);
		copyBlock(queue, queue + rear + 1, newQueue + capacity - startPos);
	}
    
	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
    
	free(queue);
	queue = newQueue;
}

/*
 함수명: enQueue
 기능: 한 개 원소를 queue에 맨 뒤에 추가함
 매개변수: int type의 값
 return 값: 없음
 */
static void	enQueue(int item)
{
    if (isFull()) {
        queueExtension();
    } else {
        queue[++rear] = item;
    }
}

/*
 함수명: deQueue
 기능: queue의 맨 앞에서 원소 1개를 삭제함
 매개변수: 없음
 return 값: 삭제된 원소
 */
static int	deQueue(void)
{
    if (isEmpty()) {
        return NULL;
    } else {
        return queue[++front];
    }
}

//
// Debugging용 함수
//
/*
 함수명: printQueue
 기능: queue에 있는 원소들의 값을 front부터 rear까지 위치와 함께 출력
 매개변수: 없음
 return 값: 없음
 */
void printQueue(void)
{
	int	pos;
    
	printf("front: %d, rear: %d\n", front, rear);
	if(isEmpty()) {
		printf("no element in queue!!!\n");
		return;
	}
    
	pos = (front + 1) % capacity;
	while(pos != rear) {
		printf("[%d, %d]\n", pos, queue[pos]);
		pos = (pos + 1) % capacity;
	}
	printf("[%d, %d]\n", pos, queue[pos]);
}

/*
 함수명: testQueue
 기능
 
 용량 1인 queue를 생성한 후 1부터 10까지 10개의 원소를 queue에 저장
 queue가 empty가 될 때까지 dequeue
 매개변수: 없음
 return 값: 없음
 */
void	testQueue(void)
{
	int	i;
    
	createQueue(2); // 20인 경우는 queueFull이 발생하지 않아서 queue 확장이 이루어지지 않음.
    // 동작이 정상적으로 이루어지면 2로 바꾸어서 queueFull을 유도하여 queueExtension()이 실행되도록 하여 테스트함.
    
	for(i=0; i < 10; i++) {
		enQueue(i);
		printf("%3d enqueued\n", i);
		printf("---- 개수 = %d -----\n", i);
		printQueue();
	}
    
	printf("----- dequeue 시작 -----\n");
	while(!isEmpty()) {
		printf("%3d dequeued\n", deQueue());
		printf("---- 개수 = %d -----\n", i);
		printQueue();
	}
	printf("\n");
    
	free(queue);
}


#endif // QUEUE_TEMPLATE