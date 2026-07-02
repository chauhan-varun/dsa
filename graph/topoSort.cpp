#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans,
         int node) {
  vis[node] = 1;
  for (int &x : adj[node]) {
    if (!vis[x])
      dfs(adj, vis, ans, x);
  }
  ans.push_back(node);
}
vector<int> topoSort(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  for (auto &v : edges)
    adj[v[0]].push_back(v[1]);

  vector<bool> vis(V, 0);
  vector<int> ans;

  for (int i = 0; i < V; i++) {
    if (!vis[i])
      dfs(adj, vis, ans, i);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
