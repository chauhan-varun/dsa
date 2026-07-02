#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &vis,
         int node) {
  vis[node] = 1;
  ans.push_back(node);

  for (int x : adj[node]) {
    if (!vis[x]) {
      dfs(adj, ans, vis, x);
    }
  }
}

vector<int> dfs(vector<vector<int>> &adj) {
  vector<int> ans;
  vector<bool> vis(adj.size(), 0);
  dfs(adj, ans, vis, 0);
  return ans;
}
