#include<stdio.h>

typedef struct stack {
    int top;
    char items[30];
}STACK;

void init(STACK *s) {
    s->top = -1;
}

int is_empty(STACK *s) {
    return s->top == -1;
}

void push(STACK *s, char ch) {
    s->items[++s->top] = ch;
}

char pop(STACK *s) {
    return s->items[s->top--];
}