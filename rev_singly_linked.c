#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

#define NODEALLOC (struct node*) malloc (sizeof(struct node))

NODEPTR create(NODEPTR slist) {
    NODEPTR temp, newnode;
    int n, i;
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

NODEPTR rev(NODEPTR slist) {
    NODEPTR current = slist;
    NODEPTR prev = NULL;
    NODEPTR nextptr;
    while(current!=NULL) {
        nextptr = current->next;
        current->next = prev;

        prev = current;
        current = nextptr;
    }

    return prev;
}

void display(NODEPTR slist) {
    NODEPTR temp = slist;
    while(temp!=NULL) {
        if(temp->next==NULL) {
            printf(" %d -> NULL", temp->data);
        } else {
            printf(" %d ->", temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    NODEPTR slist = NULL;
    slist = create(slist);

    printf("\nOriginal list :\n");
    display(slist);

    slist = rev(slist);
    
    printf("\nReversed list :\n");
    display(slist);

    return 0;
}