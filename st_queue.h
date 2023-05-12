#include<stdio.h>

#define MAX 20

typedef struct QUEUE {
    int fr, rr;
    int items[MAX];
}QUEUE;

void init(QUEUE* q) {
    q->fr = q->rr = -1;
}

int is_full(QUEUE* q) {
    return q->rr == MAX -1;
}

int is_empty(QUEUE* q) {
    return q->fr == q->rr;
}

void add(QUEUE* q, int n) {
    if(is_empty(q)) {
        q->items[++q->rr] = n;
        q->fr++;
    }
    q->items[++q->rr] = n;
}

int peek(QUEUE* q) {
    return q->items[q->fr];
}