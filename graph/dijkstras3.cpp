#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
  vector<pair<int, int>> adj[n + 1];
  for (auto &it : edges) {
    int &u = it[0], &v = it[1], &w = it[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n + 1, 1e9);
  int parent[n + 1];

  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }
  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [w, node] = pq.top();
    pq.pop();

    if (w > dist[node])
      continue;

    for (auto &[x, c] : adj[node]) {
      if (dist[node] + c < dist[x]) {
        parent[x] = node;
        dist[x] = dist[node] + c;
        pq.push({dist[x], x});
      }
    }
  }

  if (dist[n] == 1e9)
    return {-1};

  int node = n;
  vector<int> path;

  while (parent[node] != node) {
    path.push_back(node);
    node = parent[node];
  }
  path.push_back(1);
  path.push_back(dist[n]);
  reverse(path.begin(), path.end());

  return path;
}
