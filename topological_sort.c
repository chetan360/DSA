/* Topological sorting */
// condition  graph is must DAC(directed acyclic gragh)
#include<stdio.h>

int main() {
    int adj[10][10], n;
    int inDeg[10], visited[10];
    printf("Enter no. of vertices : ");
    scanf("%d", &n);

    printf("Enter 1 if vertices are adjecent otherwise 0 :\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("V%d is adjesent to V%d : ", i+1, j+1);
            scanf("%d", &adj[i][j]);
        }
        inDeg[i] = 0;
        visited[i] = 0;
    }

    //calculate indegree
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            inDeg[i] += adj[j][i];
        }
    }

    for(int c=0; c<n; c++) {
        for(int i=0; i<n; i++) {
            if(inDeg[i] == 0 && !visited[i]) {
                //print vertex having indegree 0
                printf("%d ", i+1);
                //delete vertex i.e. mark as visited
                visited[i] = 1;
                for(int j=0; j<n; j++) {
                    //vertex is deleted then related edges are also deleted
                    //therefor decrement indegree of other adj. vertices
                    if(adj[i][j] == 1) {
                        inDeg[j]--;
                    }
                }
            }
        }
    }

    return 0;
}