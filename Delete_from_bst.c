/* Assignment 1 set C. b) */
/* BST delete element count */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include"btree.h"

TREEPTR inorderSucc(TREEPTR T) {
    TREEPTR curr = T;
    while(curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

TREEPTR del(TREEPTR T, int x) {
    if(x < T->data) {
        T->left = del(T->left, x);
    } else if(x > T->data) {
        T->right = del(T->right, x);
    } else {
        if(T->left == NULL) {
            TREEPTR temp = T->right;
            free(T);
            return temp;
        } else if(T->right == NULL) {
            TREEPTR temp = T->left;
            free(T);
            return temp;
        }
        TREEPTR temp = inorderSucc(T->right);
        T->data = temp->data;
        T->right = del(T->right, temp->data);
    }
    return T;
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
    printf("\nEnter key to delete : ");
    scanf("%d", &key);
    T1 = del(T1, key);
    
    printf("Inorder treversal of BST :\n");
    inorder(T1);

    return 0;
}