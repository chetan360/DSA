#include<stdio.h>

int mat[10][10], i, j;
int n;

void readGraph() {
    printf("Enter no. of vertices : ");
    scanf("%d", &n);

    printf("If vertices are adjacent enter 1 othrwise 0\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("\nV%d is adjacent to %dV : ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayAdjMat() {
    printf("\nAdjacency matrix of given graph is :\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    readGraph();
    displayAdjMat();
    return 0;
}