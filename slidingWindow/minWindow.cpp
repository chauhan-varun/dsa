#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
  int i = 0, j = 0, minLen = 0, n = s.size(), sIdx = -1, m = t.size();

  while (j < n) {
    if(s[i]==t[j]){
      i++; j++;
    }
    while(j==m-1){
      if(j - i + 1 < minLen){
        minLen = j - i + 1;
        sIdx = i;
      }
      j = 0;
    }
    i++;
  }
  return sIdx == -1 ? "" : s.substr(sIdx, minLen);
}
