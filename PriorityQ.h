#include<stdio.h>

#define MAX 20

typedef struct queue {
    int items[MAX];
    int fr, rr;
}QUEUE;

void create(QUEUE  *q) {
    q->fr = q->rr = -1;
}

void add(QUEUE *q, int n) {
    int i;
    for(i=q->rr; i>q->fr; i--) {
        if(n>q->items[i]) {
            q->items[i+1] = q->items[i];
        } else {
            break;
        }
    }
    q->items[i+1] = n;
    q->rr++;
}

int remove(QUEUE *q) {
    return q->items[++q->fr];
}

void display(QUEUE *q) {
    int i;
    for(i=q->fr; i<=q->rr; i++) {
        printf(" %d ", q->items[i]);
    }
    printf("\n");
}