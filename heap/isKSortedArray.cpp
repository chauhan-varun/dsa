#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

void nearlySortedArr(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;

  int i = 0;

  while (i <= k) {
    pq.push(arr[i++]);
  }

  int j = 0, n = arr.size();
  while (i < n) {
    arr[j++] = pq.top();
    pq.pop();
    pq.push(arr[i++]);
  }
  while(!pq.empty()){
    arr[j++]=pq.top();
    pq.pop();
  }
}
