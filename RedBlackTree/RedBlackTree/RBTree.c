//
//  RBTree
//  WooGenius
//  2014.01.02
//


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *leftChild;
    struct node *rightChild;
    struct node *parent;
    char color; // R or B
} node_t;

typedef struct tree {
    node_t *root;
    node_t *nil;
} tree_t;

// Rotation
void leftRotate(tree_t *tree, node_t *nodeX);
void rightRotate(tree_t *tree, node_t *nodeY);

// Insertion
void rbInsert(tree_t *tree, node_t *newNode);
void rbInsertFixUp(tree_t *tree, node_t *fixUpNode);
node_t* getUncleNode(tree_t *tree, node_t *node);

// Deletion
void rbTransplant (tree_t *tree, node_t *oldNode, node_t *plantNode);
void rbDelete(tree_t *tree, node_t *node);
node_t* rbMinimumBelow(tree_t *tree, node_t *node);
void rbDeleteFixUp(tree_t *tree, node_t *node);

// Test
tree_t* makeSampleRBTree(void);
tree_t* makeSampleRBTreeForDeletion(void);
void freeRBTree(tree_t *tree, node_t *root);
void printAndCheckRBTree(tree_t *tree);
int isValidRBTree(tree_t *tree);
int getBlackHeightIfValidRBTree(tree_t *tree, node_t *node);
void printTreeWithInorder(tree_t *tree, node_t *node);

// 테스트 예제는 모두 교수님이 예시로 들어주신 강의자료에서 가져 왔습니다.
int main(void) {
    node_t *root, node;
    
    printf("Test MakeSampleRBTree\n");
    tree_t *tree = makeSampleRBTree();
    root = tree->root;
    printAndCheckRBTree(tree);
    
    printf("Test Insertion\n");
    printf("Case 1 : UncleNode가 Red\n");
    node.key = 4;
    rbInsert(tree, &node);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    printf("Case 2 : UncleNode가 Black이고 2번 Rotate\n");
    tree = makeSampleRBTree();
    root = tree->root;
    root->leftChild->rightChild->rightChild = tree->nil;
    node.key = 4;
    rbInsert(tree, &node);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);

    printf("Case 3 : UncleNode가 Black이고 1번 Rotate\n");
    tree = makeSampleRBTree();
    root = tree->root;
    root->leftChild->rightChild->rightChild = tree->nil;
    node.key = 6;
    rbInsert(tree, &node);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    printf("Test Deletion\n");
    printf("Case1 : sibling이 Black, sibling의 child가 모두 Black\n");
    tree = makeSampleRBTreeForDeletion();
    root = tree->root;
    // Test
    rbDelete(tree, tree->root->leftChild->rightChild);
    // Case1
    rbDelete(tree, tree->root->leftChild->rightChild);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    printf("Case2 : sibling이 Black, sibling의 child가 Black/Red - Red\n");
    tree = makeSampleRBTreeForDeletion();
    root = tree->root;
    rbDelete(tree, tree->root->rightChild->leftChild);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    printf("Case3 : sibling이 Black, sibling의 child가 Red - Black\n");
    tree = makeSampleRBTreeForDeletion();
    root = tree->root;
    rbDelete(tree, tree->root->leftChild->leftChild);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    printf("Case5 : sibling이 Red, sibling의 child가 모두 Black\n");
    tree = makeSampleRBTreeForDeletion();
    root = tree->root;
    rbDelete(tree, tree->root->leftChild);
    rbDelete(tree, tree->root->leftChild);
    rbDelete(tree, tree->root->leftChild->leftChild);
    // Case5
    rbDelete(tree, tree->root->leftChild);
    printAndCheckRBTree(tree);
    freeRBTree(tree, root);
    
    return 0;
}

tree_t* makeSampleRBTree(void) {
    tree_t *tree = malloc(sizeof(tree_t));
    node_t *nil = malloc(sizeof(node_t));
    node_t *node = malloc(sizeof(node_t)*8);
    
    nil->color = 'B';
    tree->nil = nil;
    tree->root = node;
    
    node[0].key = 11;
    node[0].parent = nil;
    node[0].leftChild = &node[1];
    node[0].rightChild = &node[2];
    node[0].color = 'B';
    
    node[1].key = 2;
    node[1].parent = &node[0];
    node[1].leftChild = &node[3];
    node[1].rightChild = &node[4];
    node[1].color = 'R';
    
    node[2].key = 14;
    node[2].parent = &node[0];
    node[2].leftChild = nil;
    node[2].rightChild = &node[5];
    node[2].color = 'B';
    
    node[3].key = 1;
    node[3].parent = &node[1];
    node[3].leftChild = nil;
    node[3].rightChild = nil;
    node[3].color = 'B';
    
    node[4].key = 7;
    node[4].parent = &node[1];
    node[4].leftChild = &node[6];
    node[4].rightChild = &node[7];
    node[4].color = 'B';
    
    node[5].key = 15;
    node[5].parent = &node[2];
    node[5].leftChild = nil;
    node[5].rightChild = nil;
    node[5].color = 'R';
    
    node[6].key = 5;
    node[6].parent = &node[4];
    node[6].leftChild = nil;
    node[6].rightChild = nil;
    node[6].color = 'R';
    
    node[7].key = 8;
    node[7].parent = &node[4];
    node[7].leftChild = nil;
    node[7].rightChild = nil;
    node[7].color = 'R';
    
    return tree;
}

tree_t* makeSampleRBTreeForDeletion(void) {
    tree_t *tree = malloc(sizeof(tree_t));
    node_t *nil = malloc(sizeof(node_t));
    node_t *node = malloc(sizeof(node_t)*9);
    
    nil->color = 'B';
    tree->nil = nil;
    tree->root = node;
    
    node[0].key = 7;
    node[0].parent = nil;
    node[0].leftChild = &node[1];
    node[0].rightChild = &node[2];
    node[0].color = 'B';
    
    node[1].key = 2;
    node[1].parent = &node[0];
    node[1].leftChild = &node[3];
    node[1].rightChild = &node[4];
    node[1].color = 'R';
    
    node[2].key = 11;
    node[2].parent = &node[0];
    node[2].leftChild = &node[5];
    node[2].rightChild = &node[6];
    node[2].color = 'R';
    
    node[3].key = 1;
    node[3].parent = &node[1];
    node[3].leftChild = nil;
    node[3].rightChild = nil;
    node[3].color = 'B';
    
    node[4].key = 5;
    node[4].parent = &node[1];
    node[4].leftChild = &node[7];
    node[4].rightChild = nil;
    node[4].color = 'B';
    
    node[5].key = 8;
    node[5].parent = &node[2];
    node[5].leftChild = nil;
    node[5].rightChild = nil;
    node[5].color = 'B';
    
    node[6].key = 14;
    node[6].parent = &node[2];
    node[6].leftChild = nil;
    node[6].rightChild = &node[8];
    node[6].color = 'B';
    
    node[7].key = 4;
    node[7].parent = &node[4];
    node[7].leftChild = nil;
    node[7].rightChild = nil;
    node[7].color = 'R';
    
    node[8].key = 15;
    node[8].parent = &node[6];
    node[8].leftChild = nil;
    node[8].rightChild = nil;
    node[8].color = 'R';
    
    return tree;
}

void freeRBTree(tree_t *tree, node_t *root) {
    free(tree->nil);
    free(root);
    free(tree);
}

void printAndCheckRBTree(tree_t *tree){
    printTreeWithInorder(tree, tree->root);
    printf("\n");
    if (isValidRBTree(tree)) printf("Valid RBTree\n");
    else printf("Invalid RBTree\n");
    printf("\n");
}

// Definition 2,3에 위배되거나 getBlackHeigt함수에서 -1을 리턴하면 잘못된 Red Black Tree
// Definition 1,4,5는 노드를 탐색하며 검사해야 하기때문에 하나의 함수로 만듦
int isValidRBTree(tree_t *tree) {
    // 잘 못된 입력
    if (!tree) return 0;
    
    // Definition 2 : Root는 Black
    if (tree->root->color != 'B') {
        printf("Definition 2 Violation\n");
        return 0;
    }
    
    // Definition 3 : NIL은 Black
    if (tree->nil->color != 'B') {
        printf("Definition 3 Violation\n");
        return 0;
    }
    
    // Definition 1,4,5
    if (getBlackHeightIfValidRBTree(tree, tree->root) == -1) return 0;
    
    return 1;
}

// 모든 리프노드로부터 자신까지 BlackHeight가 같으면 BlackHeight를
// 다르거나 잘못된 Red Black Tree이면 -1을 리턴하는 함수
int getBlackHeightIfValidRBTree(tree_t *tree, node_t *node) {
    int leftBlackHeight, rightBlackHeight;
    
    // 잘 못된 입력
    if (!tree || !node) return -1;
    
    // 자신이 nil이면 0리턴
    if (node==tree->nil) {
        return 0;
    } else {
        // Left, Right BlackHeight를 재귀적으로 구함
        leftBlackHeight = getBlackHeightIfValidRBTree(tree, node->leftChild);
        rightBlackHeight = getBlackHeightIfValidRBTree(tree, node->rightChild);
        
        // 양쪽 중 하나라도 -1이면 잘 못된 트리이므로 -1 리턴
        if (leftBlackHeight==-1 || rightBlackHeight==-1)
            return -1;
        
        // Definition 1 : 각 노드는 Red or Black
        if (node->color!='B' && node->color!='R') {
            printf("Definition 1 Violation\n");
            return -1;
        }
        
        // Definition 4 : 노드가 Red라면 Children은 모두 Black
        if (node->color == 'R') {
            if (node->leftChild->color!='B' || node->rightChild->color!='B') {
                printf("Definition 4 Violation\n");
                return -1;
            }
        }
        
        // node의 BlackHeight를 구하기 위해 Left나 Right Child가 Black일 경우 1을 더해 줌
        if (node->leftChild->color == 'B') leftBlackHeight++;
        if (node->rightChild->color == 'B') rightBlackHeight++;
        
        // Definition 5 : 모든 경로의 BlackHeight는 같음
        // 위에서 구한 BlackHeight가 같을 때만 BlackHeight리턴
        if (leftBlackHeight == rightBlackHeight)
            return leftBlackHeight;
        // 다를때 -1 리턴
        else {
            printf("Definition 5 Violation\n");
            return -1;
        }
    }
}

void printTreeWithInorder(tree_t *tree, node_t *node) {
    if (node && node!=tree->nil) {
        printTreeWithInorder(tree, node->leftChild);
        printf("%d ", node->key);
        printTreeWithInorder(tree, node->rightChild);
    }
}

void rbInsert(tree_t *tree, node_t *newNode) {
    if (!tree || !newNode) return;
    
    // Current, Parent 노드 초기화
    node_t *parentNode = tree->nil;
    node_t *curNode = tree->root;
    
    // NewNode 위치탐색
    while (curNode != tree->nil) {
        parentNode = curNode;
        if (newNode->key < curNode->key)
            curNode = curNode->leftChild;
        else
            curNode = curNode->rightChild;
    }
    
    // NewNode 배치
    newNode->parent = parentNode;
    if (parentNode == tree->nil)
        tree->root = newNode;
    else if (newNode->key < parentNode->key)
        parentNode->leftChild = newNode;
    else
        parentNode->rightChild = newNode;
    
    // NewNode Clild 초기화
    newNode->leftChild = tree->nil;
    newNode->rightChild = tree->nil;
    newNode->color = 'R';
    
    // RBTree 위배 처리
    rbInsertFixUp(tree, newNode);
}

void rbInsertFixUp(tree_t *tree, node_t *fixUpNode) {
    node_t *uncleNode;
    if (!tree || !fixUpNode) return;
    
    // fixUpNode의 부모가 Black일 때까지
    while (fixUpNode->parent->color == 'R') {
        uncleNode = getUncleNode(tree, fixUpNode);
        if (!uncleNode) break;
        
        // Case1,2,5,6 : UncleNode 색깔이 Red일 때
        if (uncleNode->color == 'R') {
            fixUpNode->parent->color = 'B';
            uncleNode->color = 'B';
            fixUpNode->parent->parent->color = 'R';
            fixUpNode = fixUpNode->parent->parent;
        }
        // Case3,4 : UncleNode가 Black, ParentNode가 LeftChild(UncleNode가 RightChild)
        else if (fixUpNode->parent->parent->leftChild == fixUpNode->parent) {
            // Case4 -> Case3
            if (fixUpNode == fixUpNode->parent->rightChild) {
                fixUpNode = fixUpNode->parent;
                leftRotate(tree, fixUpNode);
            }
            // Case3
            fixUpNode->parent->color = 'B';
            fixUpNode->parent->parent->color = 'R';
            rightRotate(tree, fixUpNode->parent->parent);
        }
        // Case7,8 : UncleNode가 Black, ParentNode가 RightChild
        else {
            // Case7 -> Case8
            if (fixUpNode == fixUpNode->parent->leftChild) {
                fixUpNode = fixUpNode->parent;
                rightRotate(tree, fixUpNode);
            }
            // Case8
            fixUpNode->parent->color = 'B';
            fixUpNode->parent->parent->color = 'R';
            leftRotate(tree, fixUpNode->parent->parent);
        }
    }
    tree->root->color = 'B';
}

void rbTransplant (tree_t *tree, node_t *oldNode, node_t *plantNode) {
    if (!tree || !oldNode || !plantNode) return;
    
    if (oldNode->parent == tree->nil)
        tree->root = plantNode;
    else if (oldNode->parent->rightChild == oldNode)
        oldNode->parent->rightChild = plantNode;
    else
        oldNode->parent->leftChild = plantNode;
    
    plantNode->parent = oldNode->parent;
}

void rbDelete(tree_t *tree, node_t *node) {
    node_t *fixupNode, *successor;
    char erasedColor = node->color;
    if (!tree || !node) return;
    
    if (node->leftChild == tree->nil) {
        fixupNode = node->rightChild;
        rbTransplant(tree, node, node->rightChild);
    } else if (node->rightChild == tree->nil) {
        fixupNode = node->leftChild;
        rbTransplant(tree, node, node->leftChild);
    } else {
        successor = rbMinimumBelow(tree, node->rightChild);
        erasedColor = successor->color;
        fixupNode = successor->rightChild;
        if (node->rightChild == successor) {
            fixupNode->parent = successor;
        } else {
            rbTransplant(tree, successor, successor->rightChild);
            successor->rightChild = node->rightChild;
            successor->rightChild->parent = successor;
        }
        rbTransplant(tree, node, successor);
        successor->leftChild = node->leftChild;
        successor->leftChild->parent = successor;
        successor->color = node->color;
    }
    
    if (erasedColor == 'B')
        rbDeleteFixUp(tree, fixupNode);
}

node_t* rbMinimumBelow(tree_t *tree, node_t *node) {
    if (!node) return (node_t*)NULL;
    
    while(node->leftChild != tree->nil)
        node = node->leftChild;
    
    return node;
}

void rbDeleteFixUp(tree_t *tree, node_t *fixupNode) {
    node_t *sibling;
    if (!tree || !fixupNode) return;
    
    // 처리할 노드가 root이거나 색깔이 검정색일동안 반복
    while (fixupNode!=tree->root && fixupNode->color=='B') {
        // 처리할 노드가 leftChild
        if (fixupNode == fixupNode->parent->leftChild) {
            sibling = fixupNode->parent->rightChild;
            
            // Case5 : sibling이 Red, sibling의 child가 모두 Black
            if (sibling->color=='R') {
                sibling->color = 'B';
                fixupNode->parent->color = 'R';
                leftRotate(tree, fixupNode->parent);
                sibling = fixupNode->parent->rightChild;
            }
            
            // Case1 : sibling이 Black, sibling의 child가 모두 Black
            if (sibling->leftChild->color=='B' && sibling->rightChild->color=='B') {
                sibling->color = 'R';
                fixupNode = fixupNode->parent;
                
            } else {
                // Case3 : sibling이 Black, sibling의 child가 Red - Black
                if (sibling->rightChild->color == 'B') {
                    sibling->leftChild->color = 'B';
                    sibling->color = 'R';
                    rightRotate(tree, sibling);
                    sibling = fixupNode->parent->rightChild;
                }
                // Case2 : sibling이 Black, sibling의 child가 Black/Red - Red
                sibling->color = fixupNode->parent->color;
                fixupNode->parent->color = 'B';
                sibling->rightChild->color = 'B';
                leftRotate(tree, fixupNode->parent);
                // 종료
                fixupNode = tree->root;
            }
            
        // 처리할 노드가 RightChild(LeftChild와 반대)
        } else {
            sibling = fixupNode->parent->leftChild;
            
            // Case5 : sibling이 Red, sibling의 child가 모두 Black
            if (sibling->color=='R') {
                sibling->color = 'B';
                fixupNode->parent->color = 'R';
                rightRotate(tree, fixupNode->parent);
                sibling = fixupNode->parent->leftChild;
            }
            
            // Case1 : sibling이 Black, sibling의 child가 모두 Black
            if (sibling->leftChild->color=='B' && sibling->rightChild->color=='B') {
                sibling->color = 'R';
                fixupNode = fixupNode->parent;
            } else {
                // Case3 : sibling이 Black, sibling의 child가 Black - Red
                if (sibling->leftChild->color == 'B') {
                    sibling->rightChild->color = 'B';
                    sibling->color = 'R';
                    leftRotate(tree, sibling);
                    sibling = fixupNode->parent->leftChild;
                }
                // Case2 : sibling이 Black, sibling의 child가 Red - Black/Red
                sibling->color = fixupNode->parent->color;
                fixupNode->parent->color = 'B';
                sibling->leftChild->color = 'B';
                rightRotate(tree, fixupNode->parent);
                // 종료
                fixupNode = tree->root;
            }
        }
    }
    
    fixupNode->color = 'B';
    
}

// UncleNode를 리턴하는 함수
node_t* getUncleNode(tree_t *tree, node_t *node) {
    // 잘못된 입력이거나 UncleNode가 없으면 NULL리턴
    if (!node || !tree || node->parent==tree->nil || node->parent->parent==tree->nil)
        return 0;
    
    if (node->parent->parent->rightChild == node->parent)
        return node->parent->parent->leftChild;
    else
        return node->parent->parent->rightChild;
}

void leftRotate(tree_t *tree, node_t *nodeX) {
    if (!tree || !nodeX) return;
    
    node_t *nodeY = nodeX->rightChild;
    nodeX->rightChild = nodeY->leftChild;
    if (nodeY->leftChild != tree->nil)
        nodeY->leftChild->parent = nodeX;
    
    nodeY->parent = nodeX->parent;
    if (nodeX->parent == tree->nil)
        tree->root = nodeY;
    else if (nodeX == nodeX->parent->leftChild)
        nodeX->parent->leftChild = nodeY;
    else
        nodeX->parent->rightChild = nodeY;
    
    nodeY->leftChild = nodeX;
    nodeX->parent = nodeY;
}

void rightRotate(tree_t *tree, node_t *nodeY) {
    if (!tree || !nodeY) return;
    
    node_t *nodeX = nodeY->leftChild;
    nodeY->leftChild = nodeX->rightChild;
    if (nodeX->rightChild != tree->nil)
        nodeX->rightChild->parent = nodeY;
    
    nodeX->parent = nodeY->parent;
    if (nodeY->parent == tree->nil)
        tree->root = nodeX;
    else if (nodeY == nodeY->parent->leftChild)
        nodeY->parent->leftChild = nodeX;
    else
        nodeY->parent->rightChild = nodeX;
    
    nodeX->rightChild = nodeY;
    nodeY->parent = nodeX;
}