//
//  RBTree.c
//  RBTree
//
//  Created by WooGenius on 2014. 1. 2..
//  Copyright (c) 2014년 WooGenius. All rights reserved.
//


#include <stdio.h>

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

void leftRotate(tree_t *tree, node_t *nodeX);
void rightRotate(tree_t *tree, node_t *nodeY);
void insert(tree_t *tree, node_t *newNode);
void insertFixUp(tree_t *tree, node_t *fixUpNode);
node_t* getUncleNode(tree_t *tree, node_t *node);

void insert(tree_t *tree, node_t *newNode) {
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
    insertFixUp(tree, newNode);
}

void insertFixUp(tree_t *tree, node_t *fixUpNode) {
    node_t *uncleNode;
    if (!tree || !fixUpNode) return;
    
    // fixUpNode의 부모가 Black일 때까지
    while (fixUpNode->parent->color == 'B') {
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
        else if (uncleNode->parent->rightChild == uncleNode) {
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
    if (nodeY->leftChild)
        nodeY->leftChild->parent = nodeX;
    
    nodeY->parent = nodeX->parent;
    if (!nodeX->parent)
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
    if (nodeX->rightChild)
        nodeX->rightChild->parent = nodeY;
    
    nodeX->parent = nodeY->parent;
    if (!nodeY->parent)
        tree->root = nodeX;
    else if (nodeY == nodeY->parent->leftChild)
        nodeY->parent->leftChild = nodeX;
    else
        nodeY->parent->rightChild = nodeX;
    
    nodeX->rightChild = nodeY;
    nodeY->parent = nodeX;
}