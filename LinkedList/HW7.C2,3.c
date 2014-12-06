//
//  HW7.C2,3
//  WooGenius
//  2013.11.11
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct list {
    node_t* head;
} list_t;

int lengthOfList(list_t *list);                         // HW7.C2
list_t* mergeLists(list_t *list1, list_t *list2);       // HW7.C3
node_t* makeLinkedList(list_t *list);
node_t* makeLinkedList2(list_t *list);
void printAllNodes(list_t *list);

int main(void) {
    list_t *list1 = (list_t*)malloc(sizeof(list_t));
    list_t *list2 = (list_t*)malloc(sizeof(list_t));
    list_t *mergedList;
    node_t *node1, *node2;
    
    // HW7.C2
    printf("HW7.C2\n");
    printf("Calculate length of list\n");
    node1 = makeLinkedList(list1);
    printAllNodes(list1);
    printf("Length : %d\n", lengthOfList(list1));
    free(node1);
    printf("\n");
    
    // HW7.C3
    printf("HW7.C3\n");
    printf("Merge two lists\n");
    node1 = makeLinkedList(list1);
    node2 = makeLinkedList2(list2);
    printf("List1 : ");
    printAllNodes(list1);
    printf("List2 : ");
    printAllNodes(list2);
    printf("Merged list : ");
    mergedList = mergeLists(list1, list2);
    printAllNodes(mergedList);
    
    free(node1);
    free(node2);
    
    free(mergedList);
    free(list1);
    free(list2);
    
    return 0;
}

// HW7.C2
int lengthOfList(list_t *list) {
    int count = 0;
    node_t *curNode;
    
    // Invalid Input
    if (!list) return 0; // 노드가 없으므로 0을 반환해도 문제없을 듯?
    
    curNode = list->head;
    while (curNode) {
        count++;
        curNode = curNode->next;
    }
    
    return count;
}

// HW7.C3
// 구현방법
// 1. 처음값이 작은리스트를 병합리스트의 헤드로 지정.
// 2. 두개의 리스트를 비교하면서 작은 값을 한칸 이동하고 이동하기 전의 값을 임시노드로 설정.
// 3. 이전에 지정한 임시노드의 다음노드를 새로생긴 임시노드로 설정.
// 4. NULL이 나오면 루프를 탈출해서 이어붙임.
// O(length of list1 * length of list2)의 시간복잡도를 가짐.
list_t* mergeLists(list_t *list1, list_t *list2) {
    list_t *mergedList = (list_t*)malloc(sizeof(list_t));
    // curNode1 for list1, curNode2 for list2
    node_t *curNode1, *curNode2, *tmpNode;
    
    // Invalid input
    if (!list1 && !list2) return NULL;
    else if (!list1) return list2;
    else if(!list2) return list1;
    
    curNode1 = list1->head;
    curNode2 = list2->head;
	tmpNode = (node_t*)NULL;
    
    // Set head of mergedList
    if (curNode1->data <= curNode2->data) mergedList->head = list1->head;
    else mergedList->head = list2->head;
    
    // curNode 중 하나라도 NULL이 나오면 루프가 끝남
    while (curNode1 && curNode2) {
        // curNode1이 curNode2보다 작거나 같을때 tmpNode에 저장하고 한칸이동
        if (curNode1->data <= curNode2->data) {
            if(tmpNode) tmpNode->next = curNode1;
            tmpNode = curNode1;
            curNode1 = curNode1->next;
        // curNode2이 curNode1보다 작을때 tmpNode에 저장하고 한칸이동
        } else {
            if(tmpNode) tmpNode->next = curNode2;
            tmpNode = curNode2;
            curNode2 = curNode2->next;
        }
    }
    
    // 루프가 끝나고 남은부분을 이어붙임
    if (!curNode1) tmpNode->next = curNode2;
    else if(!curNode2) tmpNode->next = curNode1;
    
    return mergedList;
}

node_t* makeLinkedList(list_t *list) {
    node_t *node = (node_t*)malloc(sizeof(node_t)*6);
    
    list->head = &node[0];
    node[0].data = 10;
    node[0].next = &node[1];
    
    node[1].data = 20;
    node[1].next = &node[2];
    
    node[2].data = 30;
    node[2].next = &node[3];
    
    node[3].data = 40;
    node[3].next = &node[4];
    
    node[4].data = 50;
    node[4].next = &node[5];
    
    node[5].data = 100;
    node[5].next = NULL;
    
    return node;
}

node_t* makeLinkedList2(list_t *list) {
    node_t *node = (node_t*)malloc(sizeof(node_t)*6);
    
    list->head = &node[0];
    node[0].data = 15;
    node[0].next = &node[1];
    
    node[1].data = 35;
    node[1].next = &node[2];
    
    node[2].data = 38;
    node[2].next = &node[3];
    
    node[3].data = 50;
    node[3].next = &node[4];
    
    node[4].data = 80;
    node[4].next = &node[5];
    
    node[5].data = 150;
    node[5].next = NULL;
    
    return node;
}

void printAllNodes(list_t *list) {
    node_t *curNode;
    
    // Invalid input
    if (!list) return;
    
    curNode = list->head;
    while (curNode) {
        if (curNode->next) {
            printf("%3d -> ", curNode->data);
        } else {
            printf("%3d\n", curNode->data);
        }
        curNode = curNode->next;
    }
}