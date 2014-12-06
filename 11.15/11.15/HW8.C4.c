//
// HW8.C4
// WooGenius
// 13.11.24
//


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char key;
    struct node *parent;
    struct node *leftChild;
    struct node *rightChild;
} node_t;

typedef struct tree {
    node_t *root;
} tree_t;

tree_t* makeSampleTree(void);
void swapTree(node_t *node);
void swapChild(node_t *node);
void printTreeWithInorder(node_t *node);


int main(void) {
    tree_t *tree;
    
    tree = makeSampleTree();
    printf("Sample Tree : ");
    printTreeWithInorder(tree->root);
    printf("\n\n");
    
    printf("Swapped Tree : ");
    swapTree(tree->root);
    printTreeWithInorder(tree->root);
    printf("\n\n");
    
    return 0;
}

// HW8.C4
// 구현방법 : Preorder Traversal을 하면서 rightChild와 leftChild를 바꿔 줌
void swapTree(node_t *node) {
    if (!node) return;
    
    if (node->leftChild || node->rightChild) { // 리프노드는 방문하지 않음
        swapChild(node);
        swapTree(node->leftChild);
        swapTree(node->rightChild);
    }
}

// HW8.C4
// Child를 바꿔주는 함수
void swapChild(node_t *node) {
    node_t *tmpNode;
    
    if(!node) return;
    
    tmpNode = node->leftChild;
    node->leftChild = node->rightChild;
    node->rightChild = tmpNode;
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

void printTreeWithInorder(node_t *node) {
    if (node) {
        printTreeWithInorder(node->leftChild);
        printf("%c", node->key);
        printTreeWithInorder(node->rightChild);
    }
}