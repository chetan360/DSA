#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

#define NODEALLOC (struct node*)malloc(sizeof(struct node))

NODEPTR create(NODEPTR slist) {
    NODEPTR temp, newnode;
    int n, i;
    printf("How many nodes : ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        newnode = NODEALLOC;
        newnode->next = NULL;
        scanf("%d", &newnode->data);

        if(slist == NULL) {
            slist = newnode;
            temp = newnode;
        }
        temp->next = newnode;
        temp = newnode;
    }
    return slist;
}

void bsort(NODEPTR slist) {
    NODEPTR p, q, end;
    for(end=NULL; end!=slist->next; end=p) {
        for(p=slist; p->next!=end; p=p->next) {
            q=p->next;
            if(p->data >  q->data) {
                int t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

void display(NODEPTR slist) {
    NODEPTR p = slist;
    while (p!=NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

int main() {
    NODEPTR slist = NULL;

    slist = create(slist);
    printf("Data before sorting :\n");
    display(slist);

    bsort(slist);

    printf("\nData after sorting :\n");
    display(slist);

    return 0;
} 