#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  int time;
  void dfs(vector<int> adj[], vector<char> &vis, vector<int> &tin, vector<int> &low, vector<char> &articulationPoint, int node,
           int parent) {
    vis[node] = 1;
    tin[node] = low[node] = time++;

    int child = 0;
    for (int &adjNode : adj[node]) {
      if (adjNode == parent)
        continue;
      if (!vis[adjNode]) {
        dfs(adj, vis, tin, low, articulationPoint, adjNode, node);

        low[node] = min(low[node], low[adjNode]);

        if (low[adjNode] >= tin[node] && parent != -1)
          articulationPoint[node] = 1;
        child++;
      } else {
        low[node] = min(low[node], tin[adjNode]);
      }
    }
    if (child > 1 && parent == -1)
      articulationPoint[node] = 1;
  }

public:
  vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
    vector<int> adj[V];
    for (auto &it : edges) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }

    vector<int> tin(V, -1);
    vector<int> low(V, -1);
    vector<char> vis(V, 0);
    vector<char> articulationPoint(V, 0);
    time = 1;

    for (int i = 0; i < V; i++) {
      if (!vis[i])
        dfs(adj, vis, tin, low, articulationPoint, i, -1);
    }

    vector<int> ans;
    for (int i = 0; i < V; i++)
      if (articulationPoint[i])
        ans.push_back(i);

    return ans.empty() ? vector<int>{-1} : ans;
  }
};
