#include<stdio.h>

#define MAX 20

typedef struct QUEUE {
    int fr, rr;
    int items[MAX];
}Q;

void enqueue(Q* q, int n) {
    q->items[++q->rr] = n;
}

void dequeue(Q* q) {
    int n;
    n = q->items[++q->fr];
    printf("%d is removed..\n", n);
}

int is_full(Q* q) {
    return q->rr == MAX - 1;
}

int is_empty(Q* q) {
    return q->fr == q->rr;
}

int main() {
    Q q;
    q.fr = q.rr = -1;
    int n, ch;

    do {
        printf("\n\n\n            MENU\n");
        printf("1. Enqueue\n2. Dqueue.\n3. Display.\n4. Exit.\n");
        printf("--------------------------------------------\n");
        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: if(is_full(&q)) {
                    printf("Queue is full..");
                } else {
                    printf("Enter a number : ");
                    scanf("%d", &n);
                    enqueue(&q, n);
                } break;
            case 2: if(is_empty(&q)) {
                    printf("Queue is empty..");
                } else {
                    dequeue(&q);
                } break;
            case 3: printf("Queue is :\n");
                for(int i=q.fr+1; i<=q.rr; i++) {
                    printf("%4d", q.items[i]);
                } break;
        }
    } while(ch != 4);

    return 0;
}