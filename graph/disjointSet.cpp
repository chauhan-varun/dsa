#include <bits/stdc++.h>
#include <vector>
using namespace std;

class DisjointSet {
private:
  vector<int> parent, rank, size;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);

    for (int node = 0; node <= n; node++)
      parent[node] = node;
  }

  int findUltimateParent(int node) {
    if (parent[node] == node)
      return node;

    return parent[node] = findUltimateParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int parentU = findUltimateParent(u);
    int parentV = findUltimateParent(v);

    if (parentU == parentV)
      return;

    if (rank[parentU] < rank[parentV])
      parent[parentU] = parentV;
    else if (rank[parentU] > rank[parentV])
      parent[parentV] = parentU;
    else {
      parent[parentU] = parentV;
      rank[parentV]++;
    }
  }
  void unionBySize(int u, int v) {
    int parentU = findUltimateParent(u);
    int parentV = findUltimateParent(v);

    if (parentU == parentV)
      return;

    if (size[parentU] < size[parentV]) {
      parent[parentU] = parentV;
      size[parentV] += size[parentU];
    } else {
      parent[parentV] = parentU;
      size[parentU] += size[parentV];
    }
  }
  bool isConnected(int u, int v) {
    return findUltimateParent(u) == findUltimateParent(v);
  }
};
