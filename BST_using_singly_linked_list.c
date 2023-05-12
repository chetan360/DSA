/* Assignment 2 set C. e) */
/* BST using singly linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

#define NODEALLOC (struct node*)malloc(sizeof(struct node));

int main() {
    /*
             5
            / \
           3  16 
          / \
         2   4
    */
    //store BST in arry in preorder manner
    int arr[5] = {5, 3, 16, 2, 4};
    
    int i=0;
    NODEPTR head, temp, newnode;
    head = NODEALLOC;
    head->data = arr[i];
    head->next = NULL;

    //inputing values in BST by preorder manner
    for(temp = head; i <= (5/2)-1; i++) {
        newnode = NODEALLOC;
        newnode->next = NULL;
        newnode->data = arr[(2*i)+1];
        temp->next = newnode;
        temp = newnode;

        NODEPTR newnode = NODEALLOC;
        newnode->next = NULL;
        newnode->data = arr[(2*i)+2];
        temp->next = newnode;
        temp = newnode;
    }

    //inorder traversal of bst
    for(temp = head; temp != NULL; temp = temp->next) {
        printf(" %d", temp->data);
    }

    return 0;
}