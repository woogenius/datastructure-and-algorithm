//
//  HW7.C1_1
//  WooGenius
//  2013.11.05
//

#include <stdio.h>
#include <stdlib.h>

// Practice 1
typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct list {
    node_t* head;
} list_t;

node_t* makeLinkedList(list_t *list);
void printAllInformationOfNodes(list_t *list);
void printAllNodes(list_t *list);
node_t* makeLinkedListByFunction(list_t *list);
void insertNodeAtFront(list_t *list, node_t *node);
node_t* searchNode(list_t *list, int key);
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
void deleteNode(list_t *list, node_t *prevN, node_t *targetN);
node_t* searchFrontNode(list_t *list, int key);
void invertLinkedList(list_t *list);
node_t* makeLinkedList2(list_t *list);
void concatenate (list_t *list1, list_t *list2);

int main(void) {
    list_t *list = (list_t*)malloc(sizeof(list_t));
    list_t *list2 = (list_t*)malloc(sizeof(list_t));
    node_t *node, *node2;
    node_t *nodeA, *nodeB;

    // Practice 1, 2
    printf("Practice 1, 2\n");
    printf("Make Linked List\n");
    node = makeLinkedList(list);
    printAllInformationOfNodes(list);
    free(node);
    
    // Practice 3, 4
    printf("Practice 3, 4\n");
    printf("Make Linked List By insertNodeAtFront Function\n");
    node = makeLinkedListByFunction(list);
    printAllNodes(list);

    // Practice 5
    printf("Practice 5\n");
    printf("Find 30 on Linked List\n");
    searchNode(list, 30);
    printf("Find 70 on Linked List\n");
    searchNode(list, 70);
    printf("\n");
    
    // Practice 6, 7
    printf("Practice 6, 7\n");
    printf("Insert 45 next to 40\n");
    nodeA = searchNode(list, 40);
    nodeB = (node_t*)malloc(sizeof(node_t));
    nodeB->data = 45;
    insertNode(list, nodeA, nodeB);
    printAllNodes(list);

    printf("Insert 5 on the head of list\n");
    nodeB = (node_t*)malloc(sizeof(node_t));
    nodeB->data = 5;
    insertNode(list, NULL, nodeB);
    printAllNodes(list);
    
    // Practice 8, 9
    printf("Practice 8, 9\n");
    printf("Delete 40\n");
    nodeA = searchNode(list, 40);
    nodeB = searchFrontNode(list, 40);
    deleteNode(list, nodeB, nodeA);
    printAllNodes(list);
    
    printf("Delete head\n");
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    deleteNode(list, NULL, list->head);
    printAllNodes(list);
    
    // Practice 10
    printf("Practice 10\n");
    printf("Make Linked List\n");
    node = makeLinkedList(list);
    printAllNodes(list);
    
    printf("Invert Linked List\n");
    invertLinkedList(list);
    printAllNodes(list);
    
    free(node);
    
    // Practice 11, 12
    printf("Practice 11, 12\n");
    printf("Make Linked List\n");
    node = makeLinkedList(list);
    node2 = makeLinkedList2(list2);
    printf("list1\n");
    printAllNodes(list);
    printf("list2\n");
    printAllNodes(list2);
    
    printf("Concatenate List1, 2\n");
    concatenate(list, list2);
    printAllNodes(list);

    free(node);
    free(node2);
    
    free(list);
    free(list2);
    
    return 0;
}

// Practice 1
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
    node[0].data = 110;
    node[0].next = &node[1];
    
    node[1].data = 120;
    node[1].next = &node[2];
    
    node[2].data = 130;
    node[2].next = &node[3];
    
    node[3].data = 140;
    node[3].next = &node[4];
    
    node[4].data = 150;
    node[4].next = &node[5];
    
    node[5].data = 200;
    node[5].next = NULL;
    
    return node;
}

// Practice 2
void printAllInformationOfNodes(list_t *list) {
    node_t *curNode;
    
    // Invalid input
    if (!list) return;
    
    curNode = list->head;
    while (curNode) {
        if (curNode->next) {
            printf("%3d | %p | %3d\n", curNode->data, curNode->next, curNode->next->data);
        } else {
            printf("%3d | %p | NULL\n", curNode->data, curNode->next);
        }
        curNode = curNode->next;
    }
    printf("\n");
}

// Practice 3
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
    printf("\n");
}

// Practice 4
node_t* makeLinkedListByFunction(list_t *list) {
    node_t *node;
    list->head = NULL;
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 100;
    insertNodeAtFront(list, node);
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 50;
    insertNodeAtFront(list, node);
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 40;
    insertNodeAtFront(list, node);
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 30;
    insertNodeAtFront(list, node);
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 20;
    insertNodeAtFront(list, node);
    
    node = (node_t*)malloc(sizeof(node_t));
    node->data = 10;
    insertNodeAtFront(list, node);
    
    return node;
}

// Practice 4
void insertNodeAtFront(list_t *list, node_t *node) {
    // Invalid input
    if (!list || !node) return;
    
    if (!list->head) {
        node->next = NULL;
        list->head = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
}

// Practice 5
node_t* searchNode(list_t *list, int key) {
    node_t *curNode;
    
    if (list) {
        curNode = list->head;
        while (curNode) {
            if (curNode->data==key) {
                printf("FIND! %d\n", key);
                return curNode;
            }
            curNode = curNode->next;
        }
    }
    
    printf("FAIL!\n");
    return (node_t*)NULL;
}

// Practice 6
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB) {
    // Invalid input
    if (!list || !nodeB) return;
    
    if (!nodeA) {
        insertNodeAtFront(list, nodeB);
    } else {
        nodeB->next = nodeA->next;
        nodeA->next = nodeB;
    }
}

// Practice 8
void deleteNode(list_t *list, node_t *prevN, node_t *targetN) {
    // Invalid input
    if (!targetN || !list) {
        printf("No More Node\n");
        return;
    }
    
    if (prevN) {
        prevN->next = targetN->next;
    } else {
        list->head = targetN->next;
    }
    
    free(targetN);
}

// Practice 8
node_t* searchFrontNode(list_t *list, int key) {
    node_t *curNode;
    
    if (list) {
        curNode = list->head;
        while (curNode) {
            if (curNode->next->data==key) {
                return curNode;
            }
            curNode = curNode->next;
        }
    }
    
    return (node_t*)NULL;
}

// Practice 10
void invertLinkedList(list_t *list) {
    node_t *newHead;
    node_t *tmpNode;
    
    // Invalid input
    if (!list) return;
    
    newHead = (node_t*)NULL;
    while (list->head) {
        tmpNode = list->head;
        list->head = list->head->next;
        tmpNode->next = newHead;
        newHead = tmpNode;
    }
    
    list->head = newHead;
}

// Practice 11
void concatenate (list_t *list1, list_t *list2) {
    node_t *tmpNode;
    
    // Invalid input
    if (!list1 || !list2) return;
    
    // Concatenate list
    if (!list1->head && !list2->head) {
        return;
    } else if (!list1->head) {
        list1->head = list2->head;
    } else {
        tmpNode = list1->head;
        while (tmpNode->next) {
            tmpNode = tmpNode->next;
        }
        tmpNode->next = list2->head;
    }
}



