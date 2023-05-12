//save this file as doublylist.h
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

typedef struct node* NODEPTR;

#define NODEALLOC (struct node*)malloc(sizeof(struct node))

NODEPTR create(NODEPTR dlist) {
    NODEPTR temp, newnode;
    int n, i;
    printf("How many nodes : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(i=0; i<n; i++) {
        newnode = NODEALLOC;
        newnode->next = newnode->prev = NULL;
        scanf("%d", &newnode->data);

        if(dlist == NULL) {
            dlist = temp = newnode;
        }
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }

    return dlist;
}

NODEPTR insert(NODEPTR dlist, int n) {
    NODEPTR temp, newnode;
    newnode = NODEALLOC;
    newnode->prev = NULL;
    newnode->data = n;
    dlist->prev = newnode;
    newnode->next = dlist;
    dlist = newnode;
    return dlist;
}

NODEPTR del(NODEPTR dlist) {
    NODEPTR temp = dlist;
    (temp->next)->prev = NULL;
    dlist = temp->next;
    free(temp);
    return dlist;
}

void display(NODEPTR dlist) {
    NODEPTR temp = dlist;

    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
