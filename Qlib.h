#include<stdio.h>

#define MAX 20

typedef struct QUEUE {
    int fr, rr;
    int items[MAX];
}Q;

void init(Q* q) {
    q->fr = q->rr = -1;
}

void enqueue(Q* q, int n) {
    q->items[++q->rr] = n;
}

int dqueue(Q* q) {
    return q->items[++q->fr];
}

int is_full(Q* q) {
    return q->rr == MAX -1;
}

int is_empty(Q* q) {
    return q->fr == q->rr;
}