#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}NODE;

NODE *temp = NULL;
NODE  *first = NULL;
NODE *second = NULL;
NODE * third = NULL;

#define NODEALLOC (NODE *)malloc(sizeof(NODE))

//create linked list
NODE* create(NODE  * head) {
    NODE  * newnode;
    int n;
    printf("\nHow many elements :  ");
    scanf("%d",&n);
    
    for(int i=0; i<n; i++) {
        newnode = NODEALLOC;
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp= newnode;
        }
        temp->next = newnode;
        temp = newnode;
    }
    
    return head;
}

// display function
void Display(NODE *head) {
    NODE *p=head;
    while (p != NULL) {
        printf ("%d ", p->data);
        p = p->next;
    }
}

// merge two linked list
void Merge(struct Node *first, struct Node *second) {
    if (first->data < second->data) {
        third = temp = first;
        first = first->next;
    } else {
        third = temp = second;
        second = second->next;  
    }
    temp->next = NULL;
    
    while (first != NULL && second != NULL) {
        if (first->data < second->data) {
            temp->next = first;
            temp = first;
            first = first->next;
        } else {
            temp->next = second;
            temp = second;
            second = second->next;
            
        }
        temp->next = NULL;
    }
    
    if (first != NULL) {
        temp->next = first;
    } else {
        temp->next = second;
    }
}

int main() {
    printf("ENTER SORTED DATA  \n");
    first = create (first);
    second = create (second);
    
    printf ("1st Linked List: ");
    Display (first);
    
    printf ("\n2nd Linked List: ");
    Display (second);
    
    Merge (first, second);
    printf ("\n\nMerged Linked List: \n");
    Display (third);
    
    return 0;
}