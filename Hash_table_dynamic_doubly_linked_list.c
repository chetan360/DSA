#include<stdio.h>
#include<stdlib.h>

struct node  {
      int data;
      struct node *prev, *next;
};

void insert(struct node *arr[]) {
      struct node *newnode, *temp;
      int x, y;
      printf("Enter data to be insert : ");
      scanf("%d", &x);

      newnode = (struct node*)malloc(sizeof(struct node));
      newnode->next = newnode->prev = NULL;
      newnode->data = x;

      y = x % 10;
      if(arr[y] == NULL) {
            arr[y] = newnode;
      } else {
      temp = arr[y];
            while(temp->next != NULL) {
                  temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = newnode;
      }
}

void display(struct node *arr[]) {
      struct node *temp;
      for(int i=0; i<10; i++) {
            temp = arr[i];
            printf("chain[%d] :", i);
            while (temp != NULL) {
                  printf(" %d ->", temp->data);
                  temp = temp->next;
            }
            printf(" NULL\n");
      }
}

int main() {
      struct node *arr[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
      int ch;
      do {
            printf("\n\n              MENU\n");
            printf("1. Insert.\n");
            printf("2. Display.\n");
            printf("3. Exit.\n");
            printf("-----------------------------------\n");

            printf("Enter your choise : ");
            scanf("%d", &ch);

            switch(ch) {
                  case 1:
                        insert(arr);
                        break;
                  case 2:
                        display(arr);
                        break;
            }
      }while(ch < 3);

      return 0;
}
