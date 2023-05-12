#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

#define NODEALLOC (struct node*) malloc (sizeof(struct node));

NODEPTR create(NODEPTR slist) {
    int i, n;
    NODEPTR temp, newnode;

    printf("How many nodes : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(i=0; i<n; i++) {
        newnode = NODEALLOC;
        newnode->next = NULL;
        scanf("%d", &newnode->data);

        if(slist == NULL) {
            slist = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return slist;
}

void display(NODEPTR slist) {
    NODEPTR temp = slist;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}