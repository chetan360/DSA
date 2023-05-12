#include<stdio.h>

#define MAX 20
#define INF 1e7 //10^7

void dijkstra(int n, int cost[][MAX], int source, int dist[MAX]) {
      //visited array for tracking visited vertices
      int visited[MAX];
      for(int i=1; i<=n; i++) {
            //mark all vertices not visited
            visited[i] = 0;
            //store dis of starting vertex to i th vertex from cost matrix
            dist[i] = cost[source][i];
      }

      //distance of starting vertex is always 0
      dist[source] = 0;
      //mark starting vertex visited
      visited[source] = 1;
      
      for(int c=1; c<=n; c++) {
            int v;
            int min = INF;

            //extract minmum weight vertex
            for(int i=1; i<=n; i++) {
                  //if distance in dist array is minimum value
                  //and vertex is not visited
                  if(dist[i] < min && visited[i] == 0) {
                        //update minimum distance
                        min = dist[i];
                        //store the min weighted vertex in v
                        v = i;
                  }
            }
            //mark min weighted fixed vertex
            visited[v] = 1;
            for(int i=1; i<=n; i++) {
                  //min(dis(i th vertex), dis(fixed vertex) + dis of fixed to i th vertex)
                  if(dist[i] > dist[v]+cost[v][i]) {
                        //store min distance in dis(i th vertex)
                        dist[i] = dist[v] + cost[v][i];
                  }
            }
      }

}

int main() {
      //cost matrix for store initial distances between all vertices
      int n, cost[MAX][MAX], dist[MAX];

      printf("How many vertices : ");
      scanf("%d", &n);

      printf("Read cost matrix :\n");
      for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                  printf("Dis between V%d to V%d is ", i, j);
                  scanf("%d", &cost[i][j]);
                  if(cost[i][j]==0) {
                        //if dis between i th and j th vertex is 0
                        //make as infinity
                        cost[i][j] = INF;
                  }
            }
      }

      int source;
      printf("\nEnter starting vertex : ");
      scanf("%d", &source);

      dijkstra(n, cost, source, dist);

      printf("\nShortest path from %d vertex to all other vertices is :\n", source);
      for(int i=1; i<=n; i++) {
            if(source != i) {
                  //dis of starting vertex is 0
                  //therefor print dis from strting vertex to all other vertices
                  printf(" min dis from V%d to V%d = %d\n", source, i, dist[i]);
            }
      }

      return 0;
}