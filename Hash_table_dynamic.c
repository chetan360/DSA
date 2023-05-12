#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *arr[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

struct node *newnode, *temp;

void insert() {
    int x, y;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter data : ");
    scanf("%d", &x);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = x;

    y = x % n;
    if(arr[y] == NULL) {
        arr[y] = newnode;
    } else {
        temp = arr[y];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        printf(" chain [%d] : ", i);
        temp = arr[i];
        while(temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int ch;
    do {
        printf("\n\n          Menu\n");
        printf("1. Insert.\n");
        printf("2. Display.\n");
        printf("3. Exit.\n");
        printf("----------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;       
            case 2:
                display();
                break;
        }
    } while(ch < 3);

    return 0;
}