#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

#define NODEALLOC (struct node*)malloc(sizeof(struct node));

NODEPTR create(NODEPTR slist) {
    NODEPTR newnode, temp;
    int n;
    printf("How many nodes : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
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

 void selec_sort(NODEPTR slist) {
    NODEPTR i, j;
    for(i=slist; i->next!=NULL; i=i->next) {
        for(j=i->next; j!=NULL; j=j->next) {
            if(i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
 }

void display(NODEPTR slist) {
    NODEPTR temp = slist;
    while(temp!=NULL) {
        if(temp->next==NULL) {
            printf("%d", temp->data);
        } else {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    NODEPTR slist = NULL;
    slist = create(slist);

    printf("Data before sorting :\n");
    display(slist);

    selec_sort(slist);
    
    printf("\nData after sorting :\n");
    display(slist);

    return 0;    
}