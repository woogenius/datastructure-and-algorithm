//
// HW8.C1_2
// WooGenius
// 13.11.18
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
void printBSTWithInorder(node_t *node);
node_t* BSTSearch(node_t *node, int key);
void printInfoOfNode(node_t *node);
node_t* BSTMinimumBelow(node_t *node);
node_t* BSTMaximumBelow(node_t *node);
node_t* BSTSuccessorOf(node_t *node);
void BSTInsertNode(tree_t *tree, node_t *givenNode);
void BSTTransplant(tree_t *tree, node_t *rmNode, node_t *mvNode);
void BSTDeleteNode(tree_t *tree, node_t *node);

int main(void) {
    tree_t *tree;
    node_t *node, *rmNode, *mvNode;
    
    // Practice 9
    printf("Practice 9 : Make Sample BST\n");
    tree = makeSampleBST();
    printBSTWithInorder(tree->root);
    printf("\n\n");
    
    // Practice 10
    printf("Practice 10 : BST Search\n");
    node = BSTSearch(tree->root, 12);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 2);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 7);
    printInfoOfNode(node);
    printf("\n");
    
    // Practice 11
    printf("Practice 11 : Minimum\n");
    node = BSTMinimumBelow(tree->root);
    printInfoOfNode(node);
    printf("\n");
    
    // Practice 12
    printf("Practice 12 : Maximum\n");
    node = BSTMaximumBelow(tree->root);
    printInfoOfNode(node);
    printf("\n");
    
    // Practice 13
    printf("Practice 13 : Successor\n");
    node = BSTSearch(tree->root, 2);
    node = BSTSuccessorOf(node);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 9);
    node = BSTSuccessorOf(node);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 12);
    node = BSTSuccessorOf(node);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 15);
    node = BSTSuccessorOf(node);
    printInfoOfNode(node);
    node = BSTSearch(tree->root, 19);
    node = BSTSuccessorOf(node);
    printInfoOfNode(node);
    printf("\n");

    free(tree->root);
    free(tree);

    // Practice 14
    printf("Practice 14 : Insert\n");
    tree = (tree_t*)malloc(sizeof(tree_t));
    
    printf("Test1\n");
    tree->root = NULL;
    node = (node_t*)malloc(sizeof(node_t)*6);
    node[0].key = 1;    BSTInsertNode(tree, &node[0]);
    node[1].key = 2;    BSTInsertNode(tree, &node[1]);
    node[2].key = 3;    BSTInsertNode(tree, &node[2]);
    node[3].key = 4;    BSTInsertNode(tree, &node[3]);
    node[4].key = 5;    BSTInsertNode(tree, &node[4]);
    node[5].key = 6;    BSTInsertNode(tree, &node[5]);
    printBSTWithInorder(tree->root);
    printf("\n");
    
    printf("Test2\n");
    tree->root = NULL;
    node[0].key = 6;    BSTInsertNode(tree, &node[0]);
    node[1].key = 5;    BSTInsertNode(tree, &node[1]);
    node[2].key = 4;    BSTInsertNode(tree, &node[2]);
    node[3].key = 3;    BSTInsertNode(tree, &node[3]);
    node[4].key = 2;    BSTInsertNode(tree, &node[4]);
    node[5].key = 1;    BSTInsertNode(tree, &node[5]);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(node);
    
    printf("Test3\n");
    tree->root = NULL;
    node = (node_t*)malloc(sizeof(node_t)*15);
    node[0].key = 8;    BSTInsertNode(tree, &node[0]);
    node[1].key = 4;    BSTInsertNode(tree, &node[1]);
    node[2].key = 2;    BSTInsertNode(tree, &node[2]);
    node[3].key = 1;    BSTInsertNode(tree, &node[3]);
    node[4].key = 3;    BSTInsertNode(tree, &node[4]);
    node[5].key = 6;    BSTInsertNode(tree, &node[5]);
    node[6].key = 5;    BSTInsertNode(tree, &node[6]);
    node[7].key = 7;    BSTInsertNode(tree, &node[7]);
    node[8].key = 12;   BSTInsertNode(tree, &node[8]);
    node[9].key = 10;   BSTInsertNode(tree, &node[9]);
    node[10].key = 9;   BSTInsertNode(tree, &node[10]);
    node[11].key = 11;  BSTInsertNode(tree, &node[11]);
    node[12].key = 13;  BSTInsertNode(tree, &node[12]);
    node[13].key = 14;  BSTInsertNode(tree, &node[13]);
    node[14].key = 15;  BSTInsertNode(tree, &node[14]);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(node);
    free(tree);
    printf("\n");
    
    // Practice 15
    printf("Practice 15 : Transplant\n");
    tree = (tree_t*)malloc(sizeof(tree_t));
    
    printf("Test1\n");
    tree->root = NULL;
    node = (node_t*)malloc(sizeof(node_t)*8);
    node[0].key = 12;   BSTInsertNode(tree, &node[0]);
    node[1].key = 5;    BSTInsertNode(tree, &node[1]);
    node[2].key = 18;   BSTInsertNode(tree, &node[2]);
    node[3].key = 2;    BSTInsertNode(tree, &node[3]);
    node[4].key = 9;    BSTInsertNode(tree, &node[4]);
    node[5].key = 15;   BSTInsertNode(tree, &node[5]);
    node[6].key = 19;   BSTInsertNode(tree, &node[6]);
    node[7].key = 17;   BSTInsertNode(tree, &node[7]);
    rmNode = BSTSearch(tree->root, 15);
    mvNode = BSTSearch(tree->root, 17);
    BSTTransplant(tree, rmNode, mvNode);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(node);
    
    printf("Test2\n");
    tree->root = NULL;
    node = (node_t*)malloc(sizeof(node_t)*7);
    node[0].key = 12;   BSTInsertNode(tree, &node[0]);
    node[1].key = 5;    BSTInsertNode(tree, &node[1]);
    node[2].key = 18;   BSTInsertNode(tree, &node[2]);
    node[3].key = 2;    BSTInsertNode(tree, &node[3]);
    node[4].key = 15;   BSTInsertNode(tree, &node[4]);
    node[5].key = 19;   BSTInsertNode(tree, &node[5]);
    node[6].key = 17;   BSTInsertNode(tree, &node[6]);
    rmNode = BSTSearch(tree->root, 5);
    mvNode = BSTSearch(tree->root, 2);
    BSTTransplant(tree, rmNode, mvNode);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(tree);
    free(node);
    printf("\n");
    
    // Practice 16
    printf("Practice 16 : Delete\n");
    printf("Test1 : Delete 13\n");
    tree = makeSampleBST();
    rmNode = BSTSearch(tree->root, 13);
    BSTDeleteNode(tree, rmNode);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(tree->root);
    free(tree);
    
    printf("Test2 : Delete 17\n");
    tree = makeSampleBST();
    rmNode = BSTSearch(tree->root, 17);
    BSTDeleteNode(tree, rmNode);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(tree->root);
    free(tree);
    
    printf("Test3 : Delete 12\n");
    tree = makeSampleBST();
    node = tree->root;
    rmNode = BSTSearch(tree->root, 12);
    BSTDeleteNode(tree, rmNode);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(node);
    free(tree);
    
    printf("Test4 : Delete Root\n");
    tree = makeSampleBST();
    node = tree->root;
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    BSTDeleteNode(tree, tree->root);
    printBSTWithInorder(tree->root);
    printf("\n");
    free(node);
    free(tree);
    
    return 0;
}

// Practice 9
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

// Practice 10
node_t* BSTSearch(node_t *node, int key) {
    if (!node) return (node_t*)NULL;
    if (node->key == key) return node;
    if (key < node->key) return BSTSearch(node->leftChild, key);
    else return BSTSearch(node->rightChild, key);
}

// Practice 11
node_t* BSTMinimumBelow(node_t *node) {
    if (!node) return (node_t*)NULL;
    
    while(node->leftChild)
        node = node->leftChild;
    
    return node;
}

// Practice 12
node_t* BSTMaximumBelow(node_t *node) {
    if (!node) return (node_t*)NULL;
    
    while(node->rightChild)
        node = node->rightChild;
    
    return node;
}

// Practice 13
node_t* BSTSuccessorOf(node_t *node) {
    node_t *tmpNode1, *tmpNode2;
    
    if (!node) return (node_t*)NULL;
    
    if (node->rightChild) {
        return BSTMinimumBelow(node->rightChild);
    } else {
        tmpNode1 = node->parent;
        tmpNode2 = node;
        while (tmpNode1 && !(tmpNode1->leftChild==tmpNode2)) {
            tmpNode2 = tmpNode1;
            tmpNode1 = tmpNode2->parent;
        }
        
        return tmpNode1;
    }
}

// Practice 14
void BSTInsertNode(tree_t *tree, node_t *givenNode) {
    node_t *parentNode, *curNode;
    if (!tree || !givenNode) return;
    
    parentNode = (node_t*)NULL;
    curNode = tree->root;
    
    while (curNode) {
        parentNode = curNode;
        if(givenNode->key < curNode->key)
            curNode = curNode->leftChild;
        else curNode = curNode->rightChild;
    }
    
    givenNode->parent = parentNode;
    
    if (parentNode==NULL) tree->root = givenNode;
    else if (givenNode->key < parentNode->key)
        parentNode->leftChild = givenNode;
    else
        parentNode->rightChild = givenNode;
    
    givenNode->leftChild = givenNode->rightChild = (node_t *)NULL;
}

// Practice 15
void BSTTransplant(tree_t *tree, node_t *rmNode, node_t *mvNode) {
    if (!tree || !rmNode) return;
    
    if(!rmNode->parent) tree->root = mvNode;
    else if(rmNode->parent->leftChild == rmNode)
        rmNode->parent->leftChild = mvNode;
    else if(rmNode->parent->rightChild == rmNode)
        rmNode->parent->rightChild = mvNode;
    if(mvNode) mvNode->parent = rmNode->parent;
}

// Practice 16
void BSTDeleteNode(tree_t *tree, node_t *node) {
    node_t *successor;
    if (!tree || !node) return;
    
    if (!node->leftChild) BSTTransplant(tree, node, node->rightChild);
    else if (!node->rightChild) BSTTransplant(tree, node, node->leftChild);
    else {
        successor = BSTSuccessorOf(node);
        if (node->rightChild != successor) {
            BSTTransplant(tree, successor, successor->rightChild);
            successor->rightChild = node->rightChild;
            successor->rightChild->parent = successor;
        }
        BSTTransplant(tree, node, successor);
        successor->leftChild = node->leftChild;
        successor->leftChild->parent = successor;
    }
}

void printBSTWithInorder(node_t *node) {
    if (node) {
        printBSTWithInorder(node->leftChild);
        printf("%d ", node->key);
        printBSTWithInorder(node->rightChild);
    }
}

void printInfoOfNode(node_t *node) {
    if (node) printf("%2d | %11p | %11p | %11p\n", node->key,
                     node->parent, node->leftChild, node->rightChild);
    else printf("Not Exist!\n");
}
