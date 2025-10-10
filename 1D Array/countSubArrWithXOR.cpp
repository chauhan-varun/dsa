#include <bits/stdc++.h>
using namespace std;
int countSubArr(vector<int> &a, int x) {

  int n = a.size(), count = 0;
  unordered_map<int, int> mpp;
  mpp[0]++;
  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= a[i];
    int rem = xr ^ x;
    count += mpp[rem];
    mpp[xr]++;
  }
  return count;
}
