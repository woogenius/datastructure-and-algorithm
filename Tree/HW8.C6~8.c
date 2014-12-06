//
// HW8.C6 ~ 8
// WooGenius
// 13.11.24
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "def.h"

tree_t* makeSampleTree(void);
void printInfoOfTree(tree_t *tree);
void printTreeWithInorder(node_t *node);
void printTreeWithPreorder(node_t *node);
void printTreeWithPostorder(node_t *node);

int main(void) {
    tree_t *tree;
    
    tree = makeSampleTree();
    
    // HW8.C6
    printf("Print Tree With Inorder(NonRecursive)\n");
    printTreeWithInorder(tree->root);
    printf("\n\n");
    
    // Hw8.C7
    printf("Print Tree With Preorder(NonRecursive)\n");
    printTreeWithPreorder(tree->root);
    printf("\n\n");
    
    // HW8.C8
    printf("Print Tree With Postorder(NonRecursive)\n");
    printTreeWithPostorder(tree->root);
    printf("\n\n");
    
    return 0;
}

// HW8.C6
void printTreeWithInorder(node_t *node) {
    if(!node) return;
    if(!createStack(32)) return;
    
    while (1) {
        while (node) {
            push(node);
            node = node->leftChild;
        }
        
        node = pop();
        if(!node) break;
        
        printf("%c", node->key);
        
        node = node->rightChild;
    }
    
    freeStack();
}

// HW8.C7
// 구현방법 : stack이 빌때까지 노드를 빼서 출력하고 오른쪽->왼쪽자식을 스택에 넣어주는 함수 구현
void printTreeWithPreorder(node_t *node) {
    if(!node) return;
    if(!createStack(32)) return;
    
    push(node);
    while (!isEmpty()) {
        node = pop();
        printf("%c", node->key);
        
        // 왼쪽->오른쪽의 순으로 출력해야 하므로 오른쪽->왼쪽의 순으로 넣음
        if(node->rightChild)
            push(node->rightChild);
        if(node->leftChild)
            push(node->leftChild);
    }
    
    freeStack();
}

// HW8.C7
// 구현방법
// 1. 이전노드가 현재노드의 부모일때, 왼쪽자식일때, 오른쪽자식이거나 현재노드와 같을때로 구분
// 2. 부모일때, 왼쪽자식이나 오른쪽 자식을 스택에삽입(왼->오의 순으로 하나만)
// 3. 왼쪽자식일때, 오른쪽자식을 스택에 삽입
// 4. 오른쪽자식(출력할 차례)이거나 같을때(오른쪽자식이 없음) 출력

void printTreeWithPostorder(node_t *node) {
    if(!node) return;
    node_t *prevNode = NULL;
    if(!createStack(32)) return;
    
    push(node);
    while (!isEmpty()) {
        node = peek();
        
        if (!prevNode || prevNode==node->parent) {
            // 왼쪽을 먼저 들렸다가 오른쪽을 가야하므로 왼쪽부터 넣음
            if(node->leftChild)
                push(node->leftChild);
            else if(node->rightChild)
                push(node->rightChild);
        } else if (node->leftChild == prevNode) {
            if (node->rightChild) {
                push(node->rightChild);
            }
        } else {
            printf("%c", node->key);
            pop();
        }
        
        prevNode = node;
    }
    
    freeStack();
}

tree_t* makeSampleTree(void) {
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
    node_t *node = (node_t*)malloc(sizeof(node_t)*9);
    
    tree->root = &node[0];
    
    node[0].key = '+';
    node[0].parent = NULL;
    node[0].leftChild = &node[1];
    node[0].rightChild = &node[2];
    
    node[1].key = '*';
    node[1].parent = &node[0];
    node[1].leftChild = &node[3];
    node[1].rightChild = &node[4];
    
    node[2].key = 'E';
    node[2].parent = &node[0];
    node[2].leftChild = NULL;
    node[2].rightChild = NULL;
    
    node[3].key = '*';
    node[3].parent = &node[1];
    node[3].leftChild = &node[5];
    node[3].rightChild = &node[6];
    
    node[4].key = 'D';
    node[4].parent = &node[1];
    node[4].leftChild = NULL;
    node[4].rightChild = NULL;
    
    node[5].key = '/';
    node[5].parent = &node[3];
    node[5].leftChild = &node[7];
    node[5].rightChild = &node[8];
    
    node[6].key = 'C';
    node[6].parent = &node[3];
    node[6].leftChild = NULL;
    node[6].rightChild = NULL;
    
    node[7].key = 'A';
    node[7].parent = &node[5];
    node[7].leftChild = NULL;
    node[7].rightChild = NULL;
    
    node[8].key = 'B';
    node[8].parent = &node[5];
    node[8].leftChild = NULL;
    node[8].rightChild = NULL;
    
    return tree;
}