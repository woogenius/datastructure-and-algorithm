//
// HW8.C1_1
// WooGenius
// 13.11.15
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
void printInfoOfTree(tree_t *tree);
void printTreeWithInorder(node_t *node);
void printTreeWithPreorder(node_t *node);
void printTreeWithPostorder(node_t *node);
node_t* copyTree(node_t *pSrcNode);
int equalTrees(node_t *first, node_t *second);
void testEquality(node_t *first, node_t *second);

int main(void) {
    tree_t *tree, *dstTree;
    
    // Practice 2
    printf("Practice 2 : Make Sample Tree\n\n");
    tree = makeSampleTree();
    
    // Practice 3
    printf("Practice 3 : Print Info Of Tree\n");
    printInfoOfTree(tree);
    
    // Practice 4
    printf("Practice 4 : Print Tree With Inorder(Recursive)\n");
    printTreeWithInorder(tree->root);
    printf("\n\n");
    
    // Practice 5
    printf("Practice 5 : Print Tree With Preorder(Recursive)\n");
    printTreeWithPreorder(tree->root);
    printf("\n\n");
    
    // Practice 6
    printf("Practice 6 : Print Tree With Postorder(Recursive)\n");
    printTreeWithPostorder(tree->root);
    printf("\n\n");
    
    // Practice 7
    printf("Practice 7 : Copy Tree\n");
    dstTree = (tree_t*)malloc(sizeof(tree_t));
    dstTree->root = copyTree(tree->root);
    printTreeWithInorder(dstTree->root);
    printf("\n\n");
    
    // Practice 8
    printf("Practice 8 : Tree Equality\n");
    testEquality((node_t*)NULL, dstTree->root);
    testEquality(tree->root, (node_t*)NULL);
    testEquality(tree->root, dstTree->root);
    dstTree->root->leftChild->leftChild->leftChild->leftChild->key = '+';
    testEquality(tree->root, dstTree->root);
    
    free(tree->root);
    free(tree);
    free(dstTree);
    
    return 0;
}

// Practice 2
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

// Practice 3
void printInfoOfTree(tree_t *tree) {
    int i;
    node_t *node;
    
    if(!tree||!tree->root) return;
    
    node = tree->root;
    for (i=0; i<9; i++) {
        printf("%c | %11p | %11p | %11p\n", node[i].key, node[i].parent,
               node[i].leftChild, node[i].rightChild);
    }
    printf("\n");
}

// Practice 4
void printTreeWithInorder(node_t *node) {
    if (node) {
        printTreeWithInorder(node->leftChild);
        printf("%c", node->key);
        printTreeWithInorder(node->rightChild);
    }
}

// Practice 5
void printTreeWithPreorder(node_t *node) {
    if (node) {
        printf("%c", node->key);
        printTreeWithPreorder(node->leftChild);
        printTreeWithPreorder(node->rightChild);
    }
}

// Practice 6
void printTreeWithPostorder(node_t *node) {
    if (node) {
        printTreeWithPostorder(node->leftChild);
        printTreeWithPostorder(node->rightChild);
        printf("%c", node->key);
    }
}

// Practice 7
node_t* copyTree(node_t *pSrcNode) {
    node_t *pDstNode;
    
    if (!pSrcNode) return (node_t*)NULL;
    
    pDstNode = (node_t*)malloc(sizeof(node_t));
    
    pDstNode->key = pSrcNode->key;
    pDstNode->leftChild = copyTree(pSrcNode->leftChild);
    pDstNode->rightChild = copyTree(pSrcNode->rightChild);
    
    return pDstNode;
}

// Practice 8
int equalTrees(node_t *first, node_t *second) {
    // 두개모두 empty
    if (!first && !second) return 1;
    // 둘중하나 empty
    if (!first || !second) return 0;
    
    if (first->key != second->key) return 0;
    if (!equalTrees(first->leftChild, second->leftChild)) return 0;
    if (!equalTrees(first->rightChild, second->rightChild)) return 0;
    
    return 1;
}

void testEquality(node_t *first, node_t *second) {
    if (equalTrees(first, second)) {
        printf("동일한TREE\n");
    } else {
        printf("다른TREE\n");
    }
}