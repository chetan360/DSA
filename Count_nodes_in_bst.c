/* Assignment 1 set A. b) */
/* BST count nodes all, leaf */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include "btree.h"

int countNodes(TREEPTR T) {
    if(T == NULL) {
        return 0;
    }
    return 1 + countNodes(T->left) + countNodes(T->right);
}

int countLeaf(TREEPTR root) {
    static int c = 0;
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        c++;
    }
    countLeaf(root->left);
    countLeaf(root->right);
    return c;
}


int main() {
    TREEPTR T;

    /*
            5
           /
          2
         / \
        1   3
    */

    T = init(T);
    T = insert(T, 5);
    T = insert(T, 2);
    T = insert(T, 3);
    T = insert(T, 1);

    printf("Tree created succesfully.\n");

    printf("Inorder treversal :\n");
    inorder(T);

    printf("\nTotal nodes = %d\n", countNodes(T) );
    printf("Total Leaf nodes = %d", countLeaf(T) );
                
    return 0;
}