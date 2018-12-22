#include <stdlib.h>
#include <stdio.h>

#define N 9
#define INF 999 // infinite, i.e. cannot be connected via the current position
#define UND -1 // undefined

static int PRIORITY_QUEUE[N];

int dijkstra(int graph[N][N], int start, int end);
int getMinimum();
void increasePriority(int v, int magnitude);
void decreasePriority(int v, int magnitude);

int main(void) {
  /* representation of verteINFes and magnitudes
   * [*][] represents the vertex (position) on the graph
   * [][*] represents the magnitude (distance) to the associated vertex
   */
  int graph[N][N] = [[INF, 4, INF, INF, INF, INF, INF, 8, INF],
                     [4, INF, 8, INF, INF, INF, INF, 11, INF],
                     [INF, 8, INF, 7, INF, 4, INF, INF, 2],
                     [INF, INF, 7, INF, 9, 14, INF, INF, INF],
                     [INF, INF, INF, 9, INF, 10, INF, INF, INF],
                     [INF, INF, 4, 14, 10, INF, 2, INF, INF],
                     [INF, INF, INF, INF, INF, 2, INF, 1, 6],
                     [8, 11, INF, INF, INF, INF, 1, INF, 7],
                     [INF, INF, 2, INF, INF, INF, 6, 7, INF]
                    ];
  printf("TEST: shortest distance from 0 - 4: %d\n", dijkstra(graph, 0, 4));
  return 0;
}

// calculates shortest ditance from one point to another
int dijkstra(int graph[N][N], int start, int end) {

  /*
   * visited variable to stop backtracking
   * magnitude variable to calculate the distance from starting node to each subsequent node
   */
  int visited[N], magnitude[N], previous[N];
  int minDistance, d;

  // variable to keep track of current position
  int pos = start;

  // initialize variables
  for(int i = 0; i < N; ++i) {
    visited[i] = 0;
    magnitude[i] = INF; // infinite, unknown magnitude from start to i
    previous[i] = UND; // undefined, predecessor of i
    addPriority(i, magnitude[i]);
  }
  magnitude[pos] = 0;

  // magnitude calculations
  while(visited[end] == 0) {
    visited[pos] = 1;
    minDistance = getMinimum();

    // looks at each neighbour of current vertex
    for(int i = 0; i < N; ++i) {
      d = magnitude[pos] + graph[pos][i];
      if(d < magnitude[i] && visited[i] == 0) {
        magnitude[i] = d;
        previous[i] = pos;
        decreasePriority(i, d);
      }
    }
  }

  return magnitude[end];
}

// returns the minimum value in the queue, i.e. the first position
int getMinimum() {
  return PRIORITY_QUEUE[0];
}

// adds the vertex and its associated magnitue to the priority queue
void addPriority(int v, int magnitude) {
  PRIORITY_QUEUE[v] = magnitude;
  return;
}

void decreasePriority(int v, int magnitude) {
  // TODO decrease priority
}

// sorts the queue
void sortQueue() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (PRIORITY_QUEUE[j] < PRIORITY_QUEUE[i]) {
        int temp = PRIORITY_QUEUE[i];
        PRIORITY_QUEUE[i] = PRIORITY_QUEUE[j];
        PRIORITY_QUEUE[j] = temp;
      }
    }
  }
  return;
}
