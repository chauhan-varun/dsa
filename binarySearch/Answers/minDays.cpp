#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int m, int j, int k) {
  int count = 0;
  int c = 0;
  for (auto x : arr) {

    if (x <= j) {
      c++;
      if (c == k) {
        count++;
        c = 0;
      }
    } else
      c = 0;
  }
  return count >= m;
}

int minDays(vector<int> &arr, int m, int k) {
  long long val = m * 1ll * k * 1ll;
  int n = arr.size();
  if (val > n)
    return -1;

  int i = *min_element(arr.begin(), arr.end());
  int j = *max_element(arr.begin(), arr.end());

  while (i <= j) {
    int mid = (i + j) / 2;
    if (possible(arr, m, mid, k))
      j = mid - 1;
    else
      i = mid + 1;
  }
  return i;
}
