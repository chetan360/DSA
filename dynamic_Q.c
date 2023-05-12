#include<stdio.h>
#include"swapnil66.h"

int main() {
    int ch, n;
    init();
    do {
        printf("\n\n          MENU\n");
        printf("1. Enqueue.\n2. Dequeue.\n3. Peek.\n4. Is empty.\n5. Exit.\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choise : ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: printf("Enter any number : ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2: if(is_empty()) {
                printf("Queue is empty.\n");
            } else {
                n = dequeue();
                printf("%d is removed.\n", n);
            }
                break;
            case 3: n = peek();
                printf("%d is at front.\n", n);
                break;
            case 4: if(is_empty()) {
                printf("Queue is empty.\n");
                break;
            }
        }
    } while(ch != 5);

    return 0;
}