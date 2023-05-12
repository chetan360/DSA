/* Assignment 1 set C. c) */
/* BST search with comparisons count */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include"btree.h"

TREEPTR search_com(TREEPTR root, int x) {
    static int comCount = 1;
    if(root == NULL) {
        printf("Total comparisons = %d\n", comCount);
        return NULL;
    }
    if(root->data == x) {
        printf("Total comparisons = %d\n", comCount);
        return root;
    }
    comCount++;
    if(x < root->data) {
        return search_com(root->left, x);
    }
    return search_com(root->right, x);
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

    int key;
    printf("\nEnter key to search : ");
    scanf("%d", &key);
    if(search_com(T1, key)) {
        printf("Found..");
    } else {
        printf("Not found..");
    }

    return 0;
}