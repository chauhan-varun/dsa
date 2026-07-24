#include <bits/stdc++.h>
#include <queue>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
  priority_queue<int> pq;
  int i = 0, n = arr.size();
  while (i < k)
    pq.push(arr[i++]);

  while (i < n) {
    if (pq.top() > arr[i]) {
      pq.pop();
      pq.push(arr[i]);
    }
    i++;
  }
  return pq.top();
}
