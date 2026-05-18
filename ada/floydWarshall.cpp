#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>> &graph, int V) {

  vector<vector<int>> dist = graph;

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF)
        cout << "INF";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}
