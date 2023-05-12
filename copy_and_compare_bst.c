/* Assignment 1 set A. a) */
/* BST copy, compare */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include "btree.h"

TREEPTR copyBST(TREEPTR T1) {
    TREEPTR newnode;
    if(T1 == NULL) {
        return NULL;
    } 
    if(T1 != NULL) {
        newnode = NODEALLOC;
        newnode->left = newnode->right = NULL;
        newnode->data = T1->data;
        newnode->left = copyBST(T1->left);
        newnode->right = copyBST(T1->right);
    }
    return newnode;
}

int compareBST(TREEPTR T1, TREEPTR T2) {
    if(T1 == NULL && T2 == NULL) {
        return 1;
    }
    if((T1 != NULL && T2 != NULL)) {

        return T1->data == T2->data && compareBST(T1->left, T2->left) && compareBST(T1->right, T2->right);
    }
            
    return 0;
}

int main() {
    TREEPTR T1, T2;

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

    printf("Inorder treversal of BST 1 :\n");
    inorder(T1);

    T2 = init(T2);
    T2 = copyBST(T1);
    printf("\nInorder treversal of BST 2 :\n");
    inorder(T2);
    
    if(compareBST(T1, T2)) {
        printf("\nBoth trees T1 and T2 are identical.");
    } else {
        printf("\nBoth trees T1 and T2 are not identical.");
    }
    return 0;
}