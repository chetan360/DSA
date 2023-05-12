/* Assignment 1 set C. a) */
/* BST sum ood, even nodes and mirror bst */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include "btree.h"

int sumOdd(TREEPTR T1) {
    static int sum = 0;
    if(T1 == NULL) {
        return 0;
    }
    if(T1->data % 2 != 0) {
        sum += T1->data;      
    }
    sumOdd(T1->left);
    sumOdd(T1->right);
    return sum;
}

int sumEven(TREEPTR T1) {
    static int sum = 0;
    if(T1 == NULL) {
        return 0;
    }
    if(T1->data % 2 == 0) {
        sum += T1->data;      
    }
    sumEven(T1->left);
    sumEven(T1->right);
    return sum;
}


TREEPTR mirrorBST(TREEPTR T) {
    TREEPTR newnode;
    if(T == NULL) {
        return NULL;
    }
    if(T != NULL) {
        newnode = NODEALLOC;
        newnode->left = newnode->right = NULL;
        newnode->data = T->data;
        newnode->left = mirrorBST(T->right);
        newnode->right = mirrorBST(T->left);
    }
    return newnode;
}

int main() {
    TREEPTR T1;

    /*
            5
           /
          2
         / \
        1   3
    */

    T1 = init(T1);
    T1 = insert(T1, 5);
    T1 = insert(T1, 2);
    T1 = insert(T1, 3);
    T1 = insert(T1, 1);

    printf("Tree created succesfully.\n");

    printf("Inorder treversal of BST :\n");
    inorder(T1);

    printf("\nSum of ood nodes = %d", sumOdd(T1));
    printf("\nSum of even nodes = %d", sumEven(T1));

    TREEPTR mirror = mirrorBST(T1);

    printf("\nMirror image of BST is :\n");
    inorder(mirror);

    /*
        5
         \
          2
         / \
        3   1
    */

    return 0;
}