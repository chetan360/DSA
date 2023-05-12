/* save this header file as btree.h */
#include<stdio.h>
#include<stdlib.h>

struct treenode {
    int data;
    struct treenode *left, *right;
};

typedef struct treenode *TREEPTR;

#define NODEALLOC (struct treenode *)malloc(sizeof(struct treenode))

TREEPTR init(TREEPTR T) {
    return T = NULL;
}

TREEPTR insert(TREEPTR T, int x) {
    if(T == NULL) {
        TREEPTR newnode;
        newnode = NODEALLOC;
        newnode->left = newnode->right = NULL;
        newnode->data = x;
        T = newnode;
        return T;
    }
    if(x < T->data) {
        T->left = insert(T->left, x);
    } else {
        T->right = insert(T->right, x);
    }
    return T;
}

void inorder(TREEPTR T) {
    if(T != NULL) {
        inorder(T->left);
        printf(" %d", T->data);
        inorder(T->right);
    }
}

void preorder(TREEPTR T) {
    if(T != NULL) {
        printf(" %d", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(TREEPTR T) {
    if(T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf(" %d", T->data);
    }
}

TREEPTR search(TREEPTR T, int x) {
    if(T == NULL) {
        return NULL;
    }
    if(T->data == x) {
        return T;
    }
    if(x < T->data) {
        return search(T->left, x);
    }
    return search(T->right, x);
}
