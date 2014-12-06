//
//  HW7.C1_2
//  WooGenius
//  2013.11.11
//

#include <stdio.h>
#include <stdlib.h>

// Practice 13
typedef struct dnode {
    int data;
    struct dnode* next;
    struct dnode* prev;
} dnode_t;

typedef struct dlist {
    dnode_t* head;
} dlist_t;

dnode_t* makeDoublyLinkedList(dlist_t *dlist);
void printAllInformationOfDnodes(dlist_t *dlist);
void printAllDnodes(dlist_t *dlist);
dnode_t* searchDnode(dlist_t *dlist, int key);
void insertDnode(dnode_t *dnode, dnode_t *newDnode);
void deleteDnode(dlist_t *dlist, dnode_t *targetN);

int main(void) {
    dlist_t *dlist = (dlist_t*)malloc(sizeof(dlist_t));
    dnode_t *dnode, *dnode2, *dnode3;
    
    // Practice 13
    printf("Practice 13\n");
    printf("Make Doubly Linked List\n\n");
    dnode = makeDoublyLinkedList(dlist);
    
    // Practice 14
    printf("Practice 14\n");
    printf("Print All Informations of DNodes\n");
    printAllInformationOfDnodes(dlist);
    
    // Practice 15
    printf("Practice 15\n");
    printf("Print All DNodes\n");
    printAllDnodes(dlist);
    
    // Practice 16
    printf("Practice 16\n");
    printf("Search DNode\n");
    searchDnode(dlist, 1);
    searchDnode(dlist, 20);
    printf("\n");
    
    // Practice 17
    printf("Practice 17\n");
    printf("Insert DNode\n");
    dnode2 = searchDnode(dlist, 16);
    dnode3 = (dnode_t*)malloc(sizeof(dnode_t));
    dnode3->data = 45;
    insertDnode(dnode2, dnode3);
    printAllDnodes(dlist);
    
    // Practice 18
    printf("Practice 18\n");
    printf("Delete DNode\n");
    dnode2 = searchDnode(dlist, 16);
    deleteDnode(dlist, dnode2);
    
    printAllDnodes(dlist);
    
    free(dnode);
    free(dnode3);
    
    return 0;
}

// Practice 13
dnode_t* makeDoublyLinkedList(dlist_t *dlist) {
    dnode_t *dnode = (dnode_t*)malloc(sizeof(dnode_t)*5);
    
    // Sentinel Node data?
    dlist->head = &dnode[0];
    dnode[0].next = &dnode[1];
    dnode[0].prev = &dnode[4];
    
    dnode[1].data = 9;
    dnode[1].next = &dnode[2];
    dnode[1].prev = &dnode[0];
    
    dnode[2].data = 16;
    dnode[2].next = &dnode[3];
    dnode[2].prev = &dnode[1];
    
    dnode[3].data = 4;
    dnode[3].next = &dnode[4];
    dnode[3].prev = &dnode[2];
    
    dnode[4].data = 1;
    dnode[4].next = &dnode[0];
    dnode[4].prev = &dnode[3];
    
    return dnode;
}

// Practice 14
void printAllInformationOfDnodes(dlist_t *dlist) {
    dnode_t *curNode;
    
    // Invalid input
    if (!dlist) return;
    
    curNode = dlist->head;
    do {
        printf("%3d | %p | %3d | %p | %3d\n", curNode->data,
               curNode->prev, curNode->prev->data, curNode->next, curNode->next->data);
        curNode = curNode->next;
    } while (curNode != dlist->head);
    
    printf("\n");
}

// Practice 15
void printAllDnodes(dlist_t *dlist) {
    dnode_t *curNode;
    
    // Invalid input
    if (!dlist) return;
    
    curNode = dlist->head->next;
    do {
        printf("<- %3d -> ", curNode->data);
        curNode = curNode->next;
    } while (curNode != dlist->head);
    
    printf("\n\n");
}

// Practice 16
dnode_t* searchDnode(dlist_t *dlist, int key) {
    dnode_t *curNode;
    
    if (dlist) {
        curNode = dlist->head;
        do {
            if (curNode->data==key) {
                printf("FIND! %d\n", key);
                return curNode;
            }
            curNode = curNode->next;
        } while (curNode != dlist->head);
    }
    
    printf("FAIL!\n");
    return (dnode_t*)NULL;
}

// Practice 17
void insertDnode(dnode_t *dnode, dnode_t *newDnode) {
    // Invalid input
    if (!dnode || !newDnode) return;
    
    // No need to check beause of dummy node
    newDnode->prev = dnode;
    newDnode->next = dnode->next;
    dnode->next = newDnode;
    newDnode->next->prev = newDnode;
}

// Practice 18
void deleteDnode(dlist_t *dlist, dnode_t *targetN) {
    // Invalid input
    if (!targetN || !dlist) return;
    
    // No need to check beause of dummy node
    targetN->next->prev = targetN->prev;
    targetN->prev->next = targetN->next;
}
