#include <bits/stdc++.h>
using namespace std;
// prims algo
pair<int, vector<pair<int, int>>> spanningTree(int V,
                                               vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V);

  for (const auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int weight = edge[2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  // {weight, node, parent}
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;

  vector<bool> visited(V, false);
  vector<pair<int, int>> mst;
  int totalWeight = 0;

  pq.push({0, 0, -1});

  while (!pq.empty()) {
    auto [weight, node, parent] = pq.top();
    pq.pop();

    if (visited[node])
      continue;

    visited[node] = true;
    totalWeight += weight;

    if (parent != -1)
      mst.push_back({parent, node});

    for (const auto &[neighbor, edgeWeight] : adj[node])
      if (!visited[neighbor])
        pq.push({edgeWeight, neighbor, node});
  }

  return {totalWeight, mst};
}
