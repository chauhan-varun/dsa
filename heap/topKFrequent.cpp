#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &arr, int k) {
  unordered_map<int, int> mpp;

  for (int x : arr)
    mpp[x]++;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  for (auto &[key, v] : mpp) {
    pq.push({v, key});
    if (pq.size() > k)
      pq.pop();
  }

  vector<int> ans;
  while (!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}
