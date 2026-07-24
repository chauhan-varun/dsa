#include <bits/stdc++.h>
#include <vector>
using namespace std;
// kruskals algo
class DisjointSet {
private:
  vector<int> parent, rank;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);

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
  bool isConnected(int u, int v) {
    return findUltimateParent(u) == findUltimateParent(v);
  }
};

pair<int, vector<pair<int, int>>> spanningTree(int V,
                                               vector<vector<int>> &edges) {
  vector<tuple<int, int, int>> sortedEdges;
  sortedEdges.reserve(edges.size());

  for (auto &it : edges)
    sortedEdges.emplace_back(it[2], it[0], it[1]);

  sort(sortedEdges.begin(), sortedEdges.end());

  DisjointSet ds(V);
  vector<pair<int, int>> mst;
  mst.reserve(V-1);
  int sum = 0;

  for (const auto &[w, u, v] : sortedEdges) {
    if (!ds.isConnected(u, v)) {
      ds.unionByRank(u, v);
      sum += w;
      mst.emplace_back(u, v);

      if((int)mst.size()==V-1)
        break;
    }
  }
  return {sum, mst};
}
