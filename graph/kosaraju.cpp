#include <bits/stdc++.h>
using namespace std;

void topo(vector<int> adj[], stack<int> &st, vector<char> &vis, int node) {
  vis[node] = 1;
  for (int &x : adj[node])
    if (!vis[x])
      topo(adj, st, vis, x);
  st.push(node);
}

void dfs(vector<int> adj[], vector<char> &vis, int node) {
  vis[node] = 1;
  for (int &x : adj[node])
    if (!vis[x])
      dfs(adj, vis, x);
}

int kosaraju(int V, vector<vector<int>> &edges) {
  vector<int> adj[V];
  vector<int> revAdj[V];

  for (auto &it : edges) {
    revAdj[it[1]].push_back(it[0]);
    adj[it[0]].push_back(it[1]);
  }

  stack<int> st;
  vector<char> vis(V, 0);
  for(int i=0; i<V; i++)
    if(!vis[i])
      topo(adj, st, vis, i);

  int scc=0;
  fill(vis.begin(), vis.end(), 0);
  while(!st.empty()){
    int node = st.top();
    st.pop();
    if(!vis[node]){
      scc++;
      dfs(revAdj, vis, node);
    }
  }
  return scc;
}
