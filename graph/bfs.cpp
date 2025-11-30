#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &arr){
  int n = arr.size();
  vector<int> vis(n, 0);
  vector<int> bfs;
  queue<int> q;

  q.push(0);
  vis[0] = 1;

  while(!q.empty()){
    int node = q.front(); q.pop();
    bfs.push_back(node);
    for(int it: arr[node]){
      if(!vis[it]){
        vis[it] = 1;
        bfs.push_back(it);
      }
    }
  }
  return bfs;
}
