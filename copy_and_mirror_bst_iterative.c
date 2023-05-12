/* Assignment 2 set C. d) */
/* iterative copy and mirror BST*/
#include"btree.h"

typedef struct queue {
    TREEPTR data[20];
    int fr, rr;
}Queue;

void enqueue(Queue *q, TREEPTR temp) {
    q->data[++q->rr] = temp;
}

TREEPTR dqueue(Queue *q) {
    return q->data[++q->fr];
}

int isEmptyQ(Queue *q) {
    return q->fr == q->rr;
}

//create mirrior by bfs 
void mirrorNonRecur(TREEPTR T) {
    if(T == NULL) {
        return;
    }
    Queue q;
    q.fr = q.rr = -1;
    enqueue(&q, T);

    while(!isEmptyQ(&q)) {
        TREEPTR temp, ptr;
        temp = dqueue(&q);
        
        //swap left child with right child
        ptr = temp->left;
        temp->left = temp->right;
        temp->right = ptr;
        
        if(temp != NULL)  {
            if(temp->left) {
                enqueue(&q, temp->left);
            }
            if(temp->right) {
                enqueue(&q, temp->right);
            }
        }
    }
}

struct copynode {
    TREEPTR current;
    TREEPTR clone;
};

typedef struct copynode *COPYPTR; 

#define COPYALLOC (struct copynode*)malloc(sizeof(struct copynode));

typedef struct stack {
    COPYPTR data[20];
    int top;
}Stack;

void push(Stack *s, COPYPTR temp) {
    s->data[++s->top] = temp;
}

COPYPTR pop(Stack *s) {
    return s->data[s->top--];
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

TREEPTR CopyNonRecur(TREEPTR root) {
    COPYPTR temp;
    temp = COPYALLOC;
    temp->current = root;
    temp->clone = NODEALLOC;
    Stack s;
    s.top = -1;
    push(&s, temp);

    while(!isEmptyStack(&s)) {
        COPYPTR ptr;
        ptr = pop(&s);
        ptr->clone = ptr->current;

        if(ptr->current->left)  {
            COPYPTR leftptr = COPYALLOC;
            leftptr->current = ptr->current->left;
            leftptr->clone = NODEALLOC;
            push(&s, leftptr);
        }
        if(ptr->current->right)  {
            COPYPTR rightptr = COPYALLOC;
            rightptr->current = ptr->current->right;
            rightptr->clone = NODEALLOC;
            push(&s, rightptr);
        }
    }
    return temp->clone;
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
    printf("Original bst :\n");
    inorder(root);

    mirrorNonRecur(root);
/*
         5
        / \
       6   3
          / \
         4   1
              \
               2
*/
    printf("\nMirror image of bst :\n");
    inorder(root);

    TREEPTR copy = CopyNonRecur(root);
    printf("\nCopy of bst :\n");
    inorder(copy);

    return 0;
}