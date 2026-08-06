#include <bits/stdc++.h>
#include <vector>
using namespace std;

int longCommSubstr(string &s, string &t) {
  int n = s.size(), m = t.size();
  vector<int> curr(m + 1, 0), prev(m + 1, 0);
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        curr[j] = 1 + prev[j - 1];
        maxi = max(maxi, curr[j]);
      } else {
        curr[j] = 0;
      }
      swap(curr, prev);
    }
  }
  return maxi;
}
