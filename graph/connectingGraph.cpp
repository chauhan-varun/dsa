#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class DSU {
private:
  vector<int> parent, rank;

public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int x) { return x == parent[x] ? x : find(parent[x]); }

  void add(int u, int v) {
    u = find(u);
    v = find(v);

    if (v == u)
      return;

    if (rank[u] < rank[v])
      parent[u] = v;
    else if (rank[v] < rank[u])
      parent[v] = u;
    else {
      parent[v] = u;
      rank[u]++;
    }
  }
};

int Solve(int V, vector<vector<int>> &edge) {
  int E = edge.size();
  if (E < V - 1)
    return -1;

  DSU ds(V);
  int extraEdges = 0;

  for (auto &it : edge) {
    if (ds.find(it[0]) == ds.find(it[1]))
      extraEdges++;
    else
      ds.add(it[0], it[1]);
  }

  int provinces = 0;
  for (int i = 0; i < V; i++)
    if (ds.find(i) == i)
      provinces++;

  int requiredEdges = provinces - 1;
  if (extraEdges < requiredEdges)
    return -1;

  return requiredEdges;
}
