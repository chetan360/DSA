#include<stdio.h>
#include"stklib.h"

int main() {
    STACK s1, s2, temp;
    init(&s1);
    init(&s2);
    init(&temp);

    int i, n, data;
    printf("How many vlaues for satck 1 : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &data);
        push(&s1, data);
    }

    while(!is_empty(&s1)) {
        push(&temp, pop(&s1));
    }

    while(!is_empty(&temp)) {
        data = pop(&temp);
        push(&s1, data);
        push(&s2, data);
    }
 
    printf("Elements are copyed..\n");

    printf("Stack 1 is :\n");
    for(i=0; i<=s1.top; i++) {
        printf(" %d ", s1.items[i]);
    }

    printf("\nStack 2 is :\n");
    for(i=0; i<=s2.top; i++) {
        printf(" %d ", s2.items[i]);
    }

    return 0;
}