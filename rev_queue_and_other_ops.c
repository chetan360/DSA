#include<stdio.h>
#include"Qlib.h"
int main() {
    Q q;
    int n, ch;
    init(&q);
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

    int i, temp;
    for(i=q.fr+1; i<=(q.rr)/2; i++) {
        temp = q.items[i];
        q.items[i] = q.items[q.rr-i];
        q.items[q.rr-i] = temp;
    }

    printf("\nReversed Queue is :\n");
    for(int i=q.fr+1; i<=q.rr; i++) {
        printf("%4d", q.items[i]);
    }

    return 0;
}