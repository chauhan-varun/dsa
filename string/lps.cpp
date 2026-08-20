#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  int getLPSLength(string &s) {
    int pIdx = 0, sIdx = 1, n = s.size();
    vector<int> lps(n, 0);
    while (sIdx < n) {
      if (s[pIdx] == s[sIdx]) {
        lps[sIdx++]=pIdx+1;
        pIdx++;
      } else {
        if (pIdx == 0)
          lps[sIdx++] = 0;
        else
          pIdx = lps[pIdx - 1];
      }
    }
    return lps[n - 1];
  }
};
