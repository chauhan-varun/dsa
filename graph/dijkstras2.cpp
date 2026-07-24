#include <bits/stdc++.h>
#include <set>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
  vector<pair<int, int>> adj[n];
  for (auto &it : edges) {
    int &u = it[0], &v = it[1], &w = it[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  set<pair<int, int>> st;
  vector<int> dist(n, 1e9);
  dist[0] = 0;
  st.insert({0, 0});

  while (!st.empty()) {
    auto [w, node] = *st.begin();
    st.erase({w, node});

    for (auto &[x, c] : adj[node]) {
      if (dist[node] + c < dist[x]) {
        if (dist[x] != 1e9)
          st.erase({dist[x], x});
        dist[x] = dist[node] + c;
        st.insert({dist[x], x});
      }
    }
  }

  for (int &x : dist)
    if (x == 1e9)
      x = -1;

  return dist;
}
