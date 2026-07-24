#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
  vector<pair<int, int>> adj[n];
  for (auto &it : edges) {
    int &u = it[0], &v = it[1], &w = it[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n, 1e9);
  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [w, node] = pq.top();
    pq.pop();

    for (auto &[x, c] : adj[node]) {
      if (dist[node] + c < dist[x]) {
        dist[x] = dist[node] + c;
        pq.push({dist[x], x});
      }
    }
  }

  for (int &x : dist)
    if (x == 1e9)
      x = -1;

  return dist;
}
