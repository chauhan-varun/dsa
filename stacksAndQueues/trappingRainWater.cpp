#include <bits/stdc++.h>
#include <vector>
using namespace std;

int trapp(vector<int> &arr) {
  int prefix = arr[0];
  int n = arr.size();
  vector<int> suffix(n);
  int total = 0;

  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }

  for (int i = 0; i < n; i++) {
    prefix = max(prefix, arr[i]);
    if (prefix > arr[i] && suffix[i] > arr[i]) {
      total += min(prefix, suffix[i]) - arr[i];
    }
  }
  return total;
}

int trap(vector<int> &arr) {
  int lMax = 0, rMax = 0, l = 0, r = arr.size() - 1, total = 0;

  while (l < r) {
    if (arr[l] <= arr[r]) {
      if (lMax > arr[l])
        total += lMax - arr[l];
      else
        lMax = arr[l];
      l++;
    } else {
      if (rMax > arr[r])
        total += rMax - arr[r];
      else
        rMax = arr[r];
      r--;
    }
  }
  return total;
}
