//
// HW8.C5
// WooGenius
// 13.11.24
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *parent;
    struct node *leftChild;
    struct node *rightChild;
} node_t;

typedef struct tree {
    node_t *root;
} tree_t;

tree_t* makeSampleBST(void);
int isVaildBST(node_t *node);
void testIsValidBST(node_t *node);
void printBSTWithInorder(node_t *node);

int main(void) {
    tree_t *tree;
    
    tree = makeSampleBST();
    printBSTWithInorder(tree->root);
    printf("\n");
    testIsValidBST(tree->root);
    
    tree->root->leftChild->key = 10;
    printBSTWithInorder(tree->root);
    printf("\n");
    testIsValidBST(tree->root);

    tree->root->leftChild->key = 5;
    tree->root->rightChild->leftChild->key = 12;
    printBSTWithInorder(tree->root);
    printf("\n");
    testIsValidBST(tree->root);
    
    free(tree->root);
    free(tree);
    
    return 0;
}

// HW8.C5
// 구현방법 : 노드의 leftChild와 rightChild값이 타당한지 확인하고 타당하면 1을 리턴하는 함수를 재귀적으로 구현
int isVaildBST(node_t *node) {
    if(!node) return 1; // node가 없어도 BST이므로 & 리프노드에서 1 리턴
    
    if(node->leftChild && node->leftChild->key > node->key) return 0;
    if(node->rightChild && node->rightChild->key < node->key) return 0;
    if(!isVaildBST(node->leftChild) || !isVaildBST(node->rightChild)) return 0;
    
    return 1;
}

void testIsValidBST(node_t *node) {
    if (isVaildBST(node)) {
        printf("Valid BST\n");
    } else {
        printf("Invalid BST\n");
    }
}


tree_t* makeSampleBST(void) {
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
    node_t *node = (node_t*)malloc(sizeof(node_t)*9);
    
    tree->root = &node[0];
    
    node[0].key = 12;
    node[0].leftChild = &node[1];
    node[0].rightChild =&node[2];
    node[0].parent = NULL;
    
    node[1].key = 5;
    node[1].leftChild = &node[3];
    node[1].rightChild = &node[4];
    node[1].parent = &node[0];
    
    node[2].key = 18;
    node[2].leftChild = &node[5];
    node[2].rightChild = &node[6];
    node[2].parent = &node[0];
    
    node[3].key = 2;
    node[3].leftChild = NULL;
    node[3].rightChild = NULL;
    node[3].parent = &node[1];
    
    node[4].key = 9;
    node[4].leftChild = NULL;
    node[4].rightChild = NULL;
    node[4].parent = &node[1];
    
    node[5].key = 15;
    node[5].leftChild = &node[7];
    node[5].rightChild = &node[8];
    node[5].parent = &node[2];
    
    node[6].key = 19;
    node[6].leftChild = NULL;
    node[6].rightChild = NULL;
    node[6].parent = &node[2];
    
    node[7].key = 13;
    node[7].leftChild = NULL;
    node[7].rightChild = NULL;
    node[7].parent = &node[5];
    
    node[8].key = 17;
    node[8].leftChild = NULL;
    node[8].rightChild = NULL;
    node[8].parent = &node[5];
    
    return tree;
}

void printBSTWithInorder(node_t *node) {
    if (node) {
        printBSTWithInorder(node->leftChild);
        printf("%d ", node->key);
        printBSTWithInorder(node->rightChild);
    }
}