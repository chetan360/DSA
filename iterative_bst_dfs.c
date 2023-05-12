/* Level wise traversal in BST */

#include "btree.h"

typedef struct stack {
    TREEPTR data[20];
    int top;
}Stack;

void push(Stack *s, TREEPTR temp) {
    s->data[++s->top] = temp;
}

TREEPTR pop(Stack *s) {
    return s->data[s->top--];
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

void dfsBst(TREEPTR root) {
    if(root == NULL) {
        return;
    }
    TREEPTR temp;
    Stack s;
    s.top = -1;
    push(&s, root);

    while(!isEmptyStack(&s)) {
        temp = pop(&s);
        printf(" %d", temp->data);
        
        if(temp->right) {
            push(&s, temp->right);
        }
        if(temp->left)  {
            push(&s, temp->left);
        }
    }
}

int main() {
    TREEPTR root;
    root = init(root);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 6);

/*
           5
          / \
         3   6
        / \
       1   4
      /
     2
*/
    printf("Tree created succesfully.\n");

    printf("Inorder treversal of BST :\n");
    inorder(root);

    printf("\nDFS treversal of BST 1 :\n");
    dfsBst(root);

    

    return 0;
}