

#ifndef _1_15_def_h
#define _1_15_def_h

typedef struct node {
    int key;
    struct node *parent;
    struct node *leftChild;
    struct node *rightChild;
} node_t;

typedef struct tree {
    node_t *root;
} tree_t;

#endif
