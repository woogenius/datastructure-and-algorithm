//
//  RBTree_test
//  WooGenius
//  2014.01.02
//


#include <stdio.h>
#include <stdlib.h>
#include "RBTree_WooGenius.c"

tree_t* makeSampleRBTree(void);
void freeRBTree(tree_t *tree);
int isValidRBTree(tree_t *tree);
int getBlackHeightIfValidRBTree(tree_t *tree, node_t *node);

int main(void) {
    
    // Test MakeSampleRBTree
    tree_t *tree = makeSampleRBTree();
    if (isValidRBTree(tree)) printf("Valid RBTree\n");
    else printf("Invalid RBTree\n");
    
    
    freeRBTree(tree);
    
    return 0;
}

tree_t* makeSampleRBTree(void) {
    tree_t *tree = malloc(sizeof(tree_t));
    node_t *nil = malloc(sizeof(node_t));
    node_t *node = malloc(sizeof(node_t)*7);
    
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
    node[4].leftChild = nil;
    node[4].rightChild = &node[6];
    node[4].color = 'B';
    
    node[5].key = 15;
    node[5].parent = &node[2];
    node[5].leftChild = nil;
    node[5].rightChild = nil;
    node[5].color = 'R';
    
    node[6].key = 9;
    node[6].parent = &node[4];
    node[6].leftChild = nil;
    node[6].rightChild = nil;
    node[6].color = 'R';
    
    return tree;
}

void freeRBTree(tree_t *tree) {
    free(tree->nil);
    free(tree->root);
    free(tree);
}

// Definition 2,3에 위배되거나 getBlackHeigt함수에서 -1을 리턴하면 잘못된 Red Black Tree
// Definition 1,4,5는 노드를 탐색하며 검사해야 하기때문에 하나의 함수로 만듬
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
