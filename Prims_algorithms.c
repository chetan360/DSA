#include<stdio.h>

#define MAX 20
#define INF 1e7

void prims(int cost[][MAX], int n) {
    int visited[MAX];
    for(int i=1; i<=n; i++) {
        visited[i] = 0;
    }
    int u, v, minCost = 0;;
    visited[1] = 1;
    for(int noEdg=1; noEdg<n; noEdg++) {
        int min = INF;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(cost[i][j] < min) {
                    if(!visited[i]) {
                        continue;
                    } else {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(!visited[u] || !visited[v]) {
            printf("%d edge (%d, %d) = %d\n", noEdg, u, v, min);
            minCost += min;
            visited[v] = 1; 
        }
        cost[u][v] = cost[v][u] = INF;
    }
    printf("Cost of MST = %d", minCost);
}

int main() {
    int n, cost[MAX][MAX], dist[MAX];

    printf("How many vertices : ");
    scanf("%d", &n);

    printf("Read cost matrix :\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("Dis between V%d to V%d is ", i, j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0) {
                cost[i][j] = INF;
            }
        }
    }

    prims(cost, n);

    return 0;
}