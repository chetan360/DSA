#include <stdio.h>
#include <stdlib.h>

struct node {
      int vertex;
      struct node *next;
};

int n;
struct node *adjList[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

void insert(int x, int y) {
      struct node *newnode, *temp;
      newnode = (struct node*)malloc(sizeof(struct node));
      newnode->next = NULL;
      newnode->vertex = y;
      if(adjList[x] == NULL) {
            adjList[x] = newnode;
      } else {
            temp = adjList[x];
            while(temp->next != NULL) {
                  temp = temp->next;
            }
            temp->next = newnode;
      }
}

void display() {
      for(int i=1; i<=n; i++) {
            struct node *temp = adjList[i];
            printf("V%d : ", i);
            while (temp != NULL) {
                  printf("V%d ->", temp->vertex);
                  temp = temp->next;
            }
            printf(" NULL\n");
      }
}

int main() {
      printf("How many edges : ", n);
      scanf("%d", &n);

      printf("Enter edge as Vi to Vj e.g.(1 2) :\n");
      for(int i=1; i<=n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert(x, y);
            insert(y, x);
      }

      display();

      return 0;
}