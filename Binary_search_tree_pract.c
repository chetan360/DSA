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
    TREEPTR newnode, temp;

    newnode = NODEALLOC;
    newnode->left = newnode->right = NULL;
    newnode->data = x;

    if(T == NULL) {
        T = newnode;
    } else {
        temp = T;
        while(temp != NULL) {
            if(x < temp->data) {
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
    
    return T;
}

void preorder(TREEPTR T) {
    if(T != NULL) {
        printf(" %d", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(TREEPTR T) {
    if(T != NULL) {
        inorder(T->left);
        printf(" %d", T->data);
        inorder(T->right);
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
    TREEPTR T;
    int ch, x;
    do {
        printf("\n         MENU\n");
        printf("1. init.\n");
        printf("2. insert.\n");
        printf("3. search.\n");
        printf("4. inorder.\n");
        printf("5. postorder.\n");
        printf("6. preorder.\n");
        printf("7. delete.\n");
        printf("8. exit.\n");
        
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
            case 7:
                printf("Enter key to delete : ");
                scanf("%d", &x);
                T = del(T, x);
                break;
        }
    } while(ch < 8);

    return 0;
}