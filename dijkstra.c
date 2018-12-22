#include <stdio.h>

#define N 9
#define INF 999 // infinite, i.e. cannot be connected via the current position
#define UND -1 // undefined

int dijkstra(int graph[N][N], int start, int end);
int getMinimum(int magnitude[N], int visited[N]);
void printSequence(int magnitude[N], int previous[N], int end);

int main(void) {
  /*
   * adjacency matrix
   * [*][] represents the vertex (position) on the graph
   * [][*] represents the magnitude (distance) to the associated vertex
   */
  int graph[N][N] = {{INF, 4, INF, INF, INF, INF, INF, 8, INF},
                     {4, INF, 8, INF, INF, INF, INF, 11, INF},
                     {INF, 8, INF, 7, INF, 4, INF, INF, 2},
                     {INF, INF, 7, INF, 9, 14, INF, INF, INF},
                     {INF, INF, INF, 9, INF, 10, INF, INF, INF},
                     {INF, INF, 4, 14, 10, INF, 2, INF, INF},
                     {INF, INF, INF, INF, INF, 2, INF, 1, 6},
                     {8, 11, INF, INF, INF, INF, 1, INF, 7},
                     {INF, INF, 2, INF, INF, INF, 6, 7, INF}
                    };
  printf("Magnitude: %d\n", dijkstra(graph, 8, 5));
  return 0;
}

// calculates shortest ditance from one point to another
int dijkstra(int graph[N][N], int start, int end) {

  /*
   * visited variable to stop backtracking, previous to track route
   * magnitude variable to calculate the distance from starting node to each subsequent node
   */
  int visited[N], magnitude[N], previous[N];
  int min, d;

  // variable to keep track of current position
  int pos = start;

  // initialize variables
  for(int i = 0; i < N; ++i) {
    visited[i] = 0;
    magnitude[i] = INF; // infinite, unknown magnitude from start to i
    previous[i] = UND; // undefined, predecessor of current vertex
  }
  magnitude[start] = 0; // magnitude from current position to start is always 0

  // magnitude calculations
  while(visited[end] == 0) {
    visited[pos] = 1;

    // looks at each neighbour of current vertex
    for(int i = 0; i < N; ++i) {
      d = magnitude[pos] + graph[pos][i];
      if(d < magnitude[i] && visited[i] == 0) {
        magnitude[i] = d;
        previous[i] = pos;
      }
    }
    pos = getMinimum(magnitude, visited);
  }
  printSequence(magnitude, previous, end);
  return magnitude[end];
}

// magnitude with sortest value is prioritized
int getMinimum(int magnitude[N], int visited[N]) {
  int min = INF;
  int m = 0;

  for(int i =0; i < N; ++i) {
    if(min > magnitude[i] && visited[i] == 0) {
      min = magnitude[i];
      m = i;
    }
  }
  return m;
}

// prints the shortest path
void printSequence(int magnitude[N], int previous[N], int end) {
  int s[N];
  int i = 0;
  int v = end;

  // backtracks through path created starting at the end
  while (v != -1){
    s[i++] = v;
    v = previous[v];
  }

  printf("Path: ");
  while(i > 0) {
    printf("%d ", s[--i]);
    if(i != 0)
      printf("-> ");
  }
  printf("\n");
  return;
}
