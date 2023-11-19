#include<stdio.h>
#include"Qlib.h"

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Queue in reverse order.");
    for(int i=q.fr+1; i<=q.rr/2; i++) {
        int t = q.items[i];
        q.items[i] = q.items[q.rr-i];
        q.items[q.rr-i] = t;  
    }

    printf("\n%d", dqueue(&q));
    printf("\n%d", dqueue(&q));
    printf("\n%d", dqueue(&q));
    printf("\n%d", dqueue(&q));
    printf("\n%d", dqueue(&q));

    return 0;
}
