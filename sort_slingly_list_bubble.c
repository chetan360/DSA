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

void bubble_sort(NODEPTR slist) {
    NODEPTR p, q, end;
    for(end=NULL; end!=slist->next; end=p) {
        for(p=slist; p->next!=end; p=p->next) {
            q = p->next;
            if(p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
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

    printf("\nList before sorting :\n");
    display(slist);

    bubble_sort(slist);
    
    printf("\nList after sorting :\n");
    display(slist);

    return 0;
}