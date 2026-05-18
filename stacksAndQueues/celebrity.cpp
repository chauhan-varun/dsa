#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &arr) {
  int i = 0, n = arr.size(), j = n - 1;

  while (i < j) {
    if (arr[i][j])
      i++;
    else 
      j--;
  }

  if (i > j)
    return -1;

  for (int k = 0; k < n; k++) {
    if (k == i)
      continue;
    if (arr[i][k] or !arr[k][i])
      return -1;
  }
  return i;
}
