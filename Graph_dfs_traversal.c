#include<stdio.h>

int mat[10][10];
int n;
int visited[10] = {0};

void readGraph() {
    printf("Enter no. of vertices : ");
    scanf("%d", &n);

    printf("If vertices are adjacent enter 1 othrwise 0\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("\nV%d is adjacent to V%d : ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void dfsTraversal(int v) {
      printf("V%d ", v+1);
      visited[v] = 1;
      for(int i=0; i<n; i++) {
            if(mat[v][i] == 1 && visited[i] == 0) {
                dfsTraversal(i);
            }
      }
      
}

int main() {
    readGraph();
    printf("DFS traversal : ");
    dfsTraversal(0);
    return 0;
}