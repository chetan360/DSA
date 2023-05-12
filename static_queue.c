#include<stdio.h>
#include"st_queue.h"

int main() {
    QUEUE q;
    q.fr = q.rr = -1;
    int n, ch;

    do {
        printf("\n\n\n            MENU\n");
        printf("1. Init\n2. Add.\n3. Peek.\n4. Exit.\n");
        printf("--------------------------------------------\n");
        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: init(&q);
                break;
            case 2: if(is_full(&q)) {
                    printf("Queue is full..");
                } else {
                    printf("Enter a number : ");
                    scanf("%d", &n);
                    add(&q, n);
                } break;
            case 3: n = peek(&q);
                printf("%d is at front.\n", n);
                break;
        }
    } while(ch != 4);

    return 0;
}