//
// HW8.C2
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

tree_t* makeSampleTree(void);
int countLeafNodes(node_t *node);
int isDegree2(node_t *node);

int main(void) {
    tree_t *tree;
    int leafNodeNum;
    
    tree = makeSampleTree();
    leafNodeNum = countLeafNodes(tree->root);
    
    printf("Leaf Node Num : %d\n", leafNodeNum);

    free(tree);
    free(tree->root);
    
    return 0;
}

// HW8.C2
// 구현방법 : Inorder Traversal을 하면서 degree가 2인 노드를 만나면 하나씩 더하고
//          마지막에 1을 더하는 방법으로 구현
// 시간복잡도 : O(n) (리프노드를 제외한 각 노드를 한번씩 방문하므로)
int countLeafNodes(node_t *node) {
    if (!node) return 0;    // 무조건 1이상을 반환하므로 0을반환하면 잘못된 입력이란 걸 알수있음
    
    static int numOfDegree2 = 0;
    
    if (node->leftChild || node->rightChild) { // 리프노드는 방문하지 않음
        countLeafNodes(node->leftChild);
        if (isDegree2(node)) numOfDegree2++;
        countLeafNodes(node->rightChild);
    }
    
    return numOfDegree2+1;
}

// HW8.C2
// Degree 가 2 이면 1을 반환하는 함수
int isDegree2(node_t *node) {
    if (!node) return 0;
    if (!node->leftChild || !node->rightChild) return 0;
    
    return 1;
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
