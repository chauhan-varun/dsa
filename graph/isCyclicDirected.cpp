#include <bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis,
            int node) {
  vis[node] = 1;
  pathVis[node] = 1;
  for (int x : adj[node]) {
    if (!vis[x] && detect(adj, vis, pathVis, x))
      return true;
    else if (pathVis[x])
      return true;
  }
  pathVis[node] = 0;
  return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  vector<bool> vis(V, 0);
  vector<bool> pathVis(V, 0);

  for (auto &v : edges) {
    adj[v[0]].push_back(v[1]);
  }

  for (int i = 0; i < V; i++) {
    if (!vis[i] && detect(adj, vis, pathVis, i))
      return true;
  }
  return false;
}
