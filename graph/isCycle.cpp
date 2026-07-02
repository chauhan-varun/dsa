#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
bool detect(vector< vector<int>> &adj, vector<bool> &vis, int src){
  queue< pair<int, int>> q;
  q.push({src, -1});
  vis[src]=1;

  while(!q.empty()){
    auto [node, parent] = q.front(); q.pop();
    for(int x: adj[node]){
      if(!vis[x]){

      vis[x]=1;
      q.push(x);
    }
  }
  return true;
}
bool isCycle(int V, vector<vector<int>> &arr) {
  int n = arr.size(), m = arr[0].size();
  vector<vector<int>> adj(V);
  for (auto &it : arr) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<bool> vis(V, 0);
  for(int i=0; i<V; i++){
    if(!vis[i]){
      if(detect(adj, vis, i))
        return true;
    }
  }
  return false;
}
