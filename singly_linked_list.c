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

NODEPTR insert(NODEPTR slist, int data) {
    NODEPTR newnode;
    newnode = NODEALLOC;
    newnode->next = slist;
    newnode->data = data;
    slist = newnode;
    return slist;
}

NODEPTR del(NODEPTR slist) {
    NODEPTR temp;
    int n;
    temp = slist;
    n = temp->data;
    printf("Deleted value is %d\n", n);
    slist = slist->next;
    free(temp);
    return slist;
}

NODEPTR del_specific(NODEPTR slist, int n) {
    NODEPTR p, q;
    p = slist;
    while(p!=NULL) {
        if((p->next)->data == n) {
            q = p->next;
            p->next = q->next;
            free(q);
            return slist;
        }
        p = p->next;
    }
    printf("Not found.\n");
    return slist;
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
    int ch, n;
    
    do {
        printf("\n\n\n          MENU\n");
        printf("1. create\n2. insert\n3. delete\n4. delete by value.\n5. display\n6. Exit\n");
        printf("__________________________________________\n");
        printf("Enter your choise : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: slist = create(slist);
                break;
            case 2: printf("Enter vlaue to be insert : ");
                scanf("%d", &n);
                slist = insert(slist, n);
                break;
            case 3: slist = del(slist);
                break;
            case 4: printf("Enter value to delete : ");
                scanf("%d", &n);
                slist = del_specific(slist, n);
                break;
            case 5: display(slist);
                printf("\n");
                break;
            default : printf("Invalide choise..\n");
        }
    } while(ch != 6);

    return 0;    
}