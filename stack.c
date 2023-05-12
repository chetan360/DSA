#include<stdio.h>

#define MAX 20

typedef struct stack {
    int top;
    int items[MAX];
}STACK;

int is_full(STACK* s) {
    return s->top == MAX -1;
}

int is_empty(STACK* s) {
    return s->top == -1;
}

void push(STACK* s, int n) {
    s->items[++s->top] = n;
}

void pop(STACK* s) {
    int n;
    n = s->items[s->top--];
    printf("%d is poped.\n", n);
}

int main() {
    STACK s;
    s.top = -1;
    int n, ch;

    do {
        printf("\n\n\n            MENU\n");
        printf("1. Push.\n2. Pop.\n3. Display.\n4. Exit.\n");
        printf("---------------------------------------\n");
        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch(ch)  {
            case 1: if(is_full(&s)) {
                printf("Stack overflow.\n");
            } else {
                printf("Enter any number : ");
                scanf("%d", &n);
                push(&s, n);
            }  break;
            case 2 : if(is_empty(&s)) {
                printf("Stack underflow.\n");
            } else {
                pop(&s);
            }  break;
            case 3 : for(int i=0; i<=s.top; i++) {
                printf("%4d", s.items[i]);
            } break;
            default: printf("Envalid choise..\n");
        }
    } while (ch != 4);

    return 0;
}