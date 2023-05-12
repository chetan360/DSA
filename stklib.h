#include<stdio.h>

#define MAX 20

typedef struct stack {
    int top;
    int items[MAX];
}STACK;

void init(STACK* s) {
    s->top = -1;
}

int is_full(STACK* s) {
    return s->top == MAX -1;
}

int is_empty(STACK* s) {
    return s->top == -1;
}

void push(STACK* s, int n) {
    s->items[++s->top] = n;
}

int pop(STACK* s) {
    return s->items[s->top--];
}