#include<stdio.h>
#include<stdlib.h>

typedef struct  node {
    int coeff, exp;
    struct node *next;
    
}NODE;

#define NODEALLOC (NODE*)malloc(sizeof(NODE))

NODE* create(NODE *poly) {
    NODE *newnode, *temp;
    int n;
    printf("How many nodes : ");
    scanf("%d", &n);

    printf("Enter %d values : \n", n);
    for(int i=0; i<n; i++) {
        newnode = NODEALLOC;
        newnode->next = NULL;
        printf("Enter coefficient : ");
        scanf("%d", &newnode->coeff);
        printf("Enter exponent : ");
        scanf("%d", &newnode->exp);

        if(poly == NULL) {
            poly = newnode;
            temp = newnode;
        }
        temp->next = newnode;
        temp = newnode;
    }
    return poly;
}

NODE* add(NODE *poly1, NODE *poly2) {
    NODE *poly3 = NULL, *temp, *newnode;
    while (poly1 != NULL && poly2 != NULL) {
        newnode = NODEALLOC;
        if(poly1->exp == poly2->exp) {
            newnode->coeff = poly1->coeff + poly2->coeff;
            newnode->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if(poly1->exp > poly2->exp) {
            newnode->coeff = poly1->coeff;
            newnode->exp = poly1->exp;
            poly1 = poly1->next;
        } else {
            newnode->coeff = poly2->coeff;
            newnode->exp = poly2->exp;
            poly2 = poly2->next;
        }
        if(poly3 == NULL) {
            poly3 = newnode;
            temp = newnode;
        }
        temp->next = newnode;
        temp = newnode;
    }
    
    if(poly1 == NULL) {
        temp->next = poly2;
    } else {
        temp->next = poly1;
    }

    return poly3;
}

void display(NODE *poly) {
    NODE *temp = poly;
    while (temp != NULL) {
        if(temp->next == NULL) {
            printf("  %dx^%d  ", temp->coeff, temp->exp);
        } else {
            printf("  %dx^%d  +", temp->coeff, temp->exp);
        }
        temp = temp->next;
    }
}

int main() {
    NODE *poly1, *poly2, *poly3;
    poly1 = poly2 = poly3 = NULL;
    poly1 = create(poly1);
    poly2 = create(poly2);
    poly3 = add(poly1, poly2);

    printf("\n\nFrist expression :\n");
    display(poly1);

    printf("\n\nSecond expression :\n");
    display(poly2);

    printf("\n\nThird expression :\n");
    display(poly3);

    return 0;
}