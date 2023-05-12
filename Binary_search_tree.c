#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct treenode {
    int data;
    struct treenode *left, *right;
};

typedef struct treenode *TREEPTR;

#define NODEALLOC (struct treenode*)malloc(sizeof(struct treenode))

TREEPTR createbst(TREEPTR root) {
    TREEPTR temp, newnode;
    int key;
    char res;
    root = NULL;

    do {
        printf("\nEnter new value : ");
        scanf("%d", &key);

        newnode = NODEALLOC;
        newnode->data = key;
        newnode->left = newnode->right = NULL;

        if(root == NULL) {
            root = newnode;
        } else {
            temp = root;
            while(temp != NULL) {
                if(key < temp->data) {
                    if(temp->left == NULL) {
                        temp->left = newnode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if(temp->right == NULL) {
                        temp->right = newnode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
        printf("Any more values (y/n) : ");
        res = getche();
    } while(res == 'y' || res == 'Y');

    return root;
}

/*TREEPTR insert(TREEPTR root, int n) {
    TREEPTR newnode, temp;
    temp = root;
    newnode = NODEALLOC;
    newnode->data = n;
    newnode->left = newnode->right = NULL;
    while(temp != NULL) {
        if(n < temp->data) {
            if(temp->left == NULL) {
                temp->left = newnode;
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if(temp->right == NULL) {
                temp->right = newnode;
                break;
            } else {
                temp = temp->right;
            }
        }  
    }
    return root;
     
}*/

TREEPTR insert(TREEPTR root, int n) {
    if(root == NULL) {
        TREEPTR newnode;
        newnode->left = newnode->right = NULL;
        newnode->data = n;
        return newnode;
    }
    if(root->left == NULL) {
        root = root->left; 
        return insert(root->left, n);

    } else {
        root = root->right; 
        return insert(root->right, n);
    }
    return root;
}

void preorder(TREEPTR root) {
    TREEPTR temp = root;
    if(temp != NULL) {
        printf("%4d", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(TREEPTR root) {
    TREEPTR temp = root;
    if(temp != NULL) {
        inorder(temp->left);
        printf("%4d", temp->data);
        inorder(temp->right);
    }
}

void postorder(TREEPTR root) {
    TREEPTR temp = root;
    if(temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%4d", temp->data);
    }
}


int countLeaf(TREEPTR root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    TREEPTR root;
    int ch, n;
    do {
        printf("\n\n           MENU\n");
        printf("1. create binary search tree.\n");
        printf("2. preorder.\n");
        printf("3. inorder.\n");
        printf("4. postorder.\n");
        printf("5. insert\n");
        printf("6. exit.\n");

        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: root = createbst(root);
                printf("\nTree created succesfully.\n");
                break;
            case 2: preorder(root);
                break;
            case 3: inorder(root);
                break;
            case 4: postorder(root);
                break;
            case 5: printf("Enter any value : ");
                scanf("%d", &n);
                root = insert(root, n);
                printf("Inserted..\n");
                break;
        }
    } while(ch < 6);

    printf("\n%d ", countLeaf(root));

    return 0;
}