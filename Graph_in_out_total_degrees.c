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

void displayDegree() {
    int ind, otd, ttd;
    for(i=0; i<n; i++) {
        ind = otd = ttd = 0;
        for(j=0; j<n; j++) {
            if(mat[i][j]) {
                otd++;
            }
            if(mat[j][i]) {
                ind++;
            }
        }
        ttd = ind + otd;
        printf("\nV%d :\n", i+1);
        printf(" indegree = %d\n outdegree = %d\n totaldegree = %d", ind, otd, ttd);
    }
}

int main() {
    readGraph();
    displayAdjMat();
    displayDegree();
    return 0;
}