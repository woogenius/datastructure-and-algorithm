//
// HW8.C3
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
void BSTInsertNodeWithRecur(node_t *currNode, node_t *parentNode, node_t *givenNode);
void printBSTWithInorder(node_t *node);
node_t* makeNewNodeWithKey(int key);

int main(void) {
    tree_t *tree;
    node_t *node1, *node2, *node3;
    
    tree = makeSampleBST();
    
    printf("Sample BST\n");
    printBSTWithInorder(tree->root);
    printf("\n");
    
    printf("Insert 11\n");
    node1 = makeNewNodeWithKey(11);
    BSTInsertNodeWithRecur(tree->root, NULL, node1);
    printBSTWithInorder(tree->root);
    printf("\n");
    
    printf("Insert 3\n");
    node2 = makeNewNodeWithKey(3);
    BSTInsertNodeWithRecur(tree->root, NULL, node2);
    printBSTWithInorder(tree->root);
    printf("\n");
    
    printf("Insert 20\n");
    node3 = makeNewNodeWithKey(20);
    BSTInsertNodeWithRecur(tree->root, NULL, node3);
    printBSTWithInorder(tree->root);
    printf("\n");
    
    free(tree->root);
    free(tree);
    free(node1);
    free(node2);
    free(node3);
    
    return 0;
}


// HW8.C3
void BSTInsertNodeWithRecur(node_t *currNode, node_t *parentNode, node_t *givenNode) {
    if(!givenNode) return;
    if(!currNode && !parentNode) return; // currNode와 parentNode가 모두없으면 잘못된 입력
    
    // currNode가 NULL일때 종료조건
    if (!currNode) {
        if (parentNode->key > givenNode->key)
            parentNode->leftChild = givenNode;
        else parentNode->rightChild = givenNode;
        
        givenNode->parent = parentNode;
        givenNode->leftChild = givenNode->rightChild = (node_t *)NULL;
        
        return;
    }
    
    // currNode와 givenNode를 비교해서 재귀함수 호출
    if (currNode->key > givenNode->key) {
        BSTInsertNodeWithRecur(currNode->leftChild, currNode, givenNode);
    } else {
        BSTInsertNodeWithRecur(currNode->rightChild, currNode, givenNode);
    }
}

// HW8.C3
// key값을 가지는 Node를 반환하는 함수
node_t* makeNewNodeWithKey(int key) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->key = key;
    
    return node;
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