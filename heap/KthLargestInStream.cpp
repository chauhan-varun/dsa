#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

  KthLargest(int k, vector<int> &arr) {
    this->k = k;
    for (int x : arr) {
      pq.push(x);
      if (pq.size() > k)
        pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k)
      pq.pop();

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
