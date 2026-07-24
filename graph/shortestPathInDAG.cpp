#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V);
  vector<int> inDegree(V, 0);

  for (auto &it : edges) {
    adj[it[0]].push_back({it[1], it[2]});
    inDegree[it[1]]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (!inDegree[i])
      q.push(i);
  }

  vector<int> topo;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    topo.push_back(node);

    for (auto &[x, c] : adj[node]) {
      if (!--inDegree[x])
        q.push(x);
    }
  }

  vector<int> dist(V, 1e9);
  dist[0] = 0;
  for (int &node : topo) {
    if (dist[node] == 1e9)
      continue;
    for (auto &[x, c] : adj[node])
      dist[x] = min(dist[x], dist[node] + c);
  }

  vector<int> ans(V, -1);
  for (int i = 0; i < V; i++) {
    if (dist[i] != 1e9)
      ans[i] = dist[i];
  }

  return ans;
}
