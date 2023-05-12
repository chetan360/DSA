/* Assignment 2 set A. a) */
/* BST level order with cout node at each level */
/* user defined libs are called inside " " */
/* include btree.h header file */
#include "btree.h"

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

void printLevelOrder(TREEPTR T) {
    if(T == NULL) {
        return;
    }
    Queue q;
    q.fr = q.rr = -1;
    enqueue(&q, T);
    enqueue(&q, NULL);
    int level = 0;
    int nodeCount = 0;

    while(!isEmptyQ(&q)) {
        TREEPTR temp;
        
        temp = dqueue(&q);
        if(temp != NULL)  {
            printf(" %d ", temp->data);
            nodeCount++;
            if(temp->left != NULL) {
                enqueue(&q, temp->left);
            }
            if(temp->right != NULL) {
                enqueue(&q, temp->right);
            }
        } else if(!isEmptyQ(&q)) {
            enqueue(&q, NULL);
            printf("\nTotal nodes at %d level = %d..\n", level, nodeCount);
            level++;
            nodeCount = 0;
        }
    }   
    printf("\nTotal nodes at %d level = %d..\n", level, nodeCount);
}

int main() {
    TREEPTR T;
    
    /*
            5         0th level
           /
          2           1st level 
         / \
        1   3         2nd level
    */

    T = init(T);
    T = insert(T, 5);
    T = insert(T, 2);
    T = insert(T, 3);
    T = insert(T, 1);

    printf("Tree created succesfully.\n");

    printf("Level order traversal :\n");
    printLevelOrder(T);

    return 0;
}