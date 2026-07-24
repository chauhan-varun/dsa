#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> topoSort(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  vector<int> intDegree(V, 0);

  for (auto &it : edges) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    intDegree[v]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (!intDegree[i])
      q.push(i);
  }

  vector<int> ans;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int &x : adj[node]) {
      intDegree[x]--;
      if (!intDegree[x])
        q.push(x);
    }
  }
  return ans;
}
