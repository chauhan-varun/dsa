#include <bits/stdc++.h>
using namespace std;
bool isMaxHeap(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i <= n / 2 - 1; i++) {
    int l = 2 * i + 1;
    int r = l + 1;
    if ((l < n && arr[l] > arr[i]) || (r < n && arr[r] > arr[i]))
      return false;
  }
  return true;
}
