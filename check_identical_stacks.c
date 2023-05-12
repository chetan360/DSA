#include<stdio.h>
#include"stklib.h"

void is_identical(STACK* s1, STACK* s2) {
    while(!is_empty(s1)) {
        if(pop(s1)!=pop(s2)) {
            printf("Both stack s1 & s2 are not identical.\n");
            return;
        }
    }
    printf("Both stack s1 & s2 are identical.\n");
}

int main() {
    STACK s1, s2;
    init(&s1);
    init(&s2);

    int i, data;

    printf("Satck 1 : ");
    printf("Enter 5 values :\n");
    for(i=0; i<5; i++) {
        scanf("%d", &data);
        push(&s1, data);
    }

    printf("Satck 2 : ");
    printf("Enter 5 values :\n");
    for(i=0; i<5; i++) {
        scanf("%d", &data);
        push(&s2, data);
    }

    is_identical(&s1, &s2);

    return 0;
}