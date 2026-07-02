#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &arr) {
  int n = arr.size();
  vector<bool> vis(n, 0);
  vector<int> ans;
  queue<int> q;

  vis[0] = 1;
  q.push(0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int e : arr[node])
      if (!vis[e]) {
        vis[e] = 1;
        q.push(e);
      }
  }
  return ans;
}
