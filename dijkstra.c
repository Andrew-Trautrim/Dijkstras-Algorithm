#include <stdlib.h>
#include <stdio.h>

#define N 9
#define X 999 // infinity, i.e. cannot be connected via the current position

int dijkstra(int graph[N][N], int start, int end);

int main(void) {
  /* representation of vertexes and magnitudes
   * [*][] represents the vertex (position) on the graph
   * [][*] represents the magnitude (distance) to the associated vertex
   */
  int graph[N][N] = [[X, 4, X, X, X, X, X, 8, X],
                     [4, X, 8, X, X, X, X, 11, X],
                     [X, 8, X, 7, X, 4, X, X, 2],
                     [X, X, 7, X, 9, 14, X, X, X],
                     [X, X, X, 9, X, 1X, X, X, X],
                     [X, X, 4, 14, 1X, X, 6, X, X],
                     [X, X, X, X, X, 2, X, 1, 6],
                     [8, 11, X, X, X, X, 1, X, 7],
                     [X, X, 2, X, X, X, 6, 7, X]
                    ];
  printf("TEST: shortest distance from 0 - 4: %d\n", dijkstra(graph, 0, 4));
  return 0;
}

// calculates shortest ditance from one point to another
int dijkstra(int graph[N][N], int start, int end) {

  /*
   * visited variable to stop backtracking
   * distance variable to calculate the distance from starting node to each subsequent node
   */
  int visited[N], distance[N];
  int minDistance, d;

  // variable to keep track of current position
  int pos = start;

  // initialize variables
  for(int i = 0; i < N; ++i) {
    visited[i] = 0;
    distance[i] = X;
  }
  distance[pos] = 0;

  // calculates minimum distance
  while(visited[end] == 0) {
    visited[pos] = 1;
    minDistance = X;

    // looks at each neighbour of current vertex
    for(int i = 0; i < N; ++i) {
      d = distance[pos] + graph[pos][i];
      if(d < distance[i] && visited[i] == 0) {
        distance[i] = d;
        previous[i] = pos;
      }
    }

    // **FIX**
    // iterate to next position
  }

  return distance[end];
}
