//floyed warshall algorithm
#include<stdio.h>

#define INF 1e7

void floydWarshall(int cost[10][10], int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(cost[i][j] > cost[i][k]+cost[k][j]) {
                    //k is an intermediate vertex in shortest path from i to j
                    //udate cost[i][j] = cost[i][k] + cost[i][j]
                    cost[i][j] = cost[i][k]+cost[k][j]; 
                }
            }
        }
    }
}

int main() {
    int cost[10][10], n, dist[10];
    printf("How many vertices : ");
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("Distence between V%d to V%d : ", i, j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0 && i!=j) {
                cost[i][j]=INF;
            }
        }
    }
    
    floydWarshall(cost, n);
    
    printf("Shortest path between each paire of vertex is :\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("V%d to V%d = %d\n", i, j, cost[i][j]);
        }
    }
    
    return 0;
}