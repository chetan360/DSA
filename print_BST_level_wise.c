/* Level wise traversal in BST */

#include "btree.h"

struct queue {
    TREEPTR items[10];
    int fr;
    int rr;
};

typedef struct queue QUEUE;

void enqueue(QUEUE *q,TREEPTR T) {
    q->items[++q->rr] = T; 
}

TREEPTR dqueue(QUEUE *q) {
    return q->items[++q->fr];
}

int isemptyQ(QUEUE *q) {
    return q->fr == q->rr;
}

void printLevelOrder(TREEPTR T) {
    if(T == NULL) {
        return;
    }
    QUEUE q;
    q.fr = q.rr = -1;
    enqueue(&q, T);
    enqueue(&q, NULL);

    while(!isemptyQ(&q)) {
        TREEPTR temp;
        temp = dqueue(&q);
        if(temp != NULL)  {
            printf(" %d ", temp->data);
            if(temp->left != NULL) {
                enqueue(&q, temp->left);
            }
            if(temp->right != NULL) {
                enqueue(&q, temp->right);
            }
        } else if(!isemptyQ(&q)) {
            enqueue(&q, NULL);
        }
    }   
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

    printf("\nLevel order treversal of BST 1 :\n");
    printLevelOrder(T1);

    return 0;
}