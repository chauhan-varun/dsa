#include <bits/stdc++.h>
using namespace std;
class DSU {
private:
  vector<int> parent;
  vector<int> size;

public:
  DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

  int find(int node) {
    if (parent[node] == node)
      return node;

    return parent[node] = find(parent[node]);
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return false;

    if (size[u] < size[v])
      swap(u, v);

    parent[v] = u;
    size[u] += size[v];

    return true;
  }
};

class Solution {
public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
    DSU ds(n * m);

    // char needs less memory than int.
    vector<char> visited(n * m, false);
    vector<int> answer;
    answer.reserve(A.size());

    const int drow[] = {-1, 0, 1, 0};
    const int dcol[] = {0, 1, 0, -1};

    int islands = 0;

    for (const auto &operation : A) {
      int row = operation[0];
      int col = operation[1];
      int node = row * m + col;

      // Duplicate operation
      if (visited[node]) {
        answer.push_back(islands);
        continue;
      }

      visited[node] = true;
      islands++;

      for (int direction = 0; direction < 4; direction++) {
        int newRow = row + drow[direction];
        int newCol = col + dcol[direction];

        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
          continue;
        }

        int adjacentNode = newRow * m + newCol;

        if (visited[adjacentNode] && ds.merge(node, adjacentNode)) {
          islands--;
        }
      }

      answer.push_back(islands);
    }

    return answer;
  }
};
