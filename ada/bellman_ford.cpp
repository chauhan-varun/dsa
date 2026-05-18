#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

// Number of vertices in the graph
#define V 5

/**
 * Function that implements Bellman-Ford single source shortest path algorithm.
 * This algorithm can handle negative edge weights and detect negative cycles.
 * 
 * @param graph: 2D adjacency matrix representing the graph
 * @param src: The starting vertex (source)
 */
void bellmanFord(int graph[V][V], int src) {
  // dist[i] will hold the shortest distance from src to i
  vector<int> dist(V, INT_MAX);

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // 1. Relax all edges V - 1 times. A simple shortest path from
  // src to any other vertex can have at-most V - 1 edges
  for (int i = 0; i < V - 1; i++) {
    for (int u = 0; u < V; u++) {
      for (int v = 0; v < V; v++) {
        // If there is an edge from u to v and u is reachable
        if (graph[u][v] != 0 && dist[u] != INT_MAX) {
          // If the path through u is shorter than the current distance to v
          if (dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
          }
        }
      }
    }
  }

  // 2. Check for negative-weight cycles. If we can still relax an edge,
  // then there is a cycle that keeps decreasing the path weight.
  for (int u = 0; u < V; u++) {
    for (int v = 0; v < V; v++) {
      if (graph[u][v] != 0 && dist[u] != INT_MAX) {
        if (dist[u] + graph[u][v] < dist[v]) {
          cout << "Graph contains negative weight cycle" << endl;
          return;
        }
      }
    }
  }

  // Print the constructed distance array
  cout << "Vertex\tDistance from Source\n";
  for (int i = 0; i < V; i++) {
    if (dist[i] == INT_MAX) {
      cout << i << "\t" << "INF" << endl;
    } else {
      cout << i << "\t" << dist[i] << endl;
    }
  }
}

int main() {
  /* Sample graph represented as an adjacency matrix
     The value graph[i][j] represents the weight of the edge from i to j.
     0 means no edge. This version includes negative weights. */
  int graph[V][V] = {{0, -1, 4, 0, 0},
                     {0, 0, 3, 2, 2},
                     {0, 0, 0, 0, 0},
                     {0, 1, 5, 0, 0},
                     {0, 0, 0, -3, 0}};

  // Run the algorithm starting from vertex 0
  bellmanFord(graph, 0);

  return 0;
}
