#include <bits/stdc++.h>
using namespace std;
bool detect(vector<vector<int>> &adj, vector<bool> &vis, int node) {
  // bfs 
  queue<int> q;
  q.push(node);
  vis[node] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int x : adj[curr]) {
      if (!vis[x]) {
        vis[x] = 1;
        q.push(x);
      }
    }
  }
  return false;
}
bool detect(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent) {
  vis[node] = 1;
  for (int x : adj[node]) {
    if (!vis[x]) {
      if (detect(adj, vis, x, node))
        return true;
    } else if (parent != x)
      return true;
  }
  return false;
}

bool isCycle(int V, vector<vector<int>> &arr) {
  vector<vector<int>> adj(V);
  for (auto &it : arr) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (detect(adj, vis, i, -1))
        return true;
    }
  }
  return false;
}
