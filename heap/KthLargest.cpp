#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

int findKthLargest(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
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
