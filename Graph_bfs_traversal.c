#include<stdio.h>

int mat[10][10];
int n;

#define MAX 20

struct queue {
      int items[MAX];
      int fr, rr;
};

void enqueue(struct queue *q, int n) {
      q->items[++q->rr] = n;
}

int dqueue(struct queue *q) {
      return q->items[++q->fr];
}

int isEmpty(struct queue *q) {
      return q->fr == q->rr;
}

void readGraph() {
    printf("Enter no. of vertices : ");
    scanf("%d", &n);

    printf("If vertices are adjacent enter 1 othrwise 0\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("\nV%d is adjacent to %dV : ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void bfsTraversal() {
      int visited[10];
      for(int i=0; i<n; i++) {
            visited[i] = 0;
      }

      int v = 0;
      visited[v] = 1;
      printf("V%d ", v+1);

      struct queue q;
      q.fr = q.rr = -1;
      enqueue(&q, v);
      while(!isEmpty(&q)) {
            int node = dqueue(&q);
            for(int i=0; i<n; i++) {
                  if(mat[node][i] == 1 && visited[i] == 0) {
                        printf(" V%d", i+1);
                        visited[i] = 1;
                        enqueue(&q, i);
                  }
            }
      }
      
}

int main() {
    readGraph();
    printf("BFS traversal : ");
    bfsTraversal();
    return 0;
}