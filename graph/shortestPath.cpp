#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
  vector<vector<int>> adj(V);
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dist(V, 1e9);
  queue<int> q;

  q.push(src);
  dist[src] = 0;

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    for (int &x : adj[node]) {
      if (dist[node] + 1 < dist[x]) {
        dist[x] = dist[node] + 1;
        q.push(x);
      }
    }
  }

  return dist[dest] == 1e9 ? -1 : dist[dest];
}
