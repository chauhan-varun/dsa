#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

// Number of vertices in the graph
#define V 5

/**
 * Function to find the vertex with the minimum distance value, from
 * the set of vertices not yet included in the shortest path tree.
 *
 * @param dist: Current shortest distance from source to each vertex
 * @param visited: Boolean array where visited[i] is true if vertex i is
 * included in shortest path tree
 * @return: Index of the vertex with the minimum distance
 */
int minDistance(vector<int> &dist, vector<bool> &visited) {
  int mini = INT_MAX; // Initialize min value to infinity
  int index = -1;

  for (int i = 0; i < V; i++) {
    // If vertex i is not visited and its distance is smaller than current mini
    if (!visited[i] && dist[i] < mini) {
      mini = dist[i];
      index = i;
    }
  }

  return index;
}

/**
 * Function that implements Dijkstra's single source shortest path algorithm
 * for a graph represented using adjacency matrix representation.
 *
 * @param graph: 2D adjacency matrix representing the graph
 * @param src: The starting vertex (source)
 */
void dijkstra(int graph[V][V], int src) {
  // dist[i] will hold the shortest distance from src to i
  vector<int> dist(V, INT_MAX);

  // visited[i] will be true if vertex i is included in shortest path tree
  // or shortest distance from src to i is finalized
  vector<bool> visited(V, false);

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++) {

    // 1. Pick the minimum distance vertex from the set of vertices not yet
    // processed. u is always equal to src in the first iteration.
    int u = minDistance(dist, visited);

    // 2. Mark the picked vertex as processed
    visited[u] = true;

    // 3. Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++) {

      // Update dist[v] only if:
      // - it is not in visited
      // - there is an edge from u to v
      // - total weight of path from src to v through u is smaller than current
      // value of dist[v]
      if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v]) {

        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  // Print the constructed distance array
  cout << "Vertex\tDistance from Source\n";
  for (int i = 0; i < V; i++) {
    cout << i << "\t" << dist[i] << endl;
  }
}


int main() {
  /* Sample graph represented as an adjacency matrix
     The value graph[i][j] represents the weight of the edge from i to j.
     0 means no edge. */
  int graph[V][V] = {{0, 10, 0, 30, 100},
                     {10, 0, 50, 0, 0},
                     {0, 50, 0, 20, 10},
                     {30, 0, 20, 0, 60},
                     {100, 0, 10, 60, 0}};

  // Run the algorithm starting from vertex 0
  dijkstra(graph, 0);

  return 0;
}
