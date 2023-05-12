/* Assignment 1 set A. a) */
/* BST menu driven program */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include "btree.h"

int main() {
    TREEPTR T;
    int ch, x;
    do {
        printf("\n         MENU\n");
        printf("1. create.\n");
        printf("2. insert.\n");
        printf("3. search.\n");
        printf("4. inorder.\n");
        printf("5. postorder.\n");
        printf("6. preorder.\n");
        printf("7. exit.\n");
        
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                T = init(T);
                printf("Tree created succesfully.\n");
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d", &x);
                T = insert(T, x);
                break;
            case 3:
                printf("Enter key to search : ");
                scanf("%d", &x);
                if(search(T, x) == NULL) {
                    printf("Not found.\n");
                } else {
                    printf("Found.\n");
                }
                break;
            case 4:
                inorder(T);
                printf("\n");
                break;
            case 5:
                postorder(T);
                printf("\n");
                break;
            case 6:
                preorder(T);
                printf("\n");
                break;
        }
    } while(ch < 7);

    return 0;
}