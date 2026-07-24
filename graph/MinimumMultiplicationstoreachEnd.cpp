#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int minSteps(vector<int> &arr, int start, int end) {
  if (start == end)
    return 0;
  const int MOD = 1000;
  vector<int> dist(MOD, INT_MAX);
  queue<pair<int, int>> q; // multiplication, node

  dist[start] = 0;
  q.push({0, start});

  while (!q.empty()) {

    auto [m, node] = q.front();
    q.pop();

    if(node == end) 
      return m;

    if (m > dist[node])
      continue;

    for (int &x : arr) {
      int next = (int)(((long long)x * node) % MOD);
      if (m + 1 < dist[next]) {
        dist[next] = m + 1;
        q.push({dist[next], next});
      }
    }
  }
  return -1;
}
