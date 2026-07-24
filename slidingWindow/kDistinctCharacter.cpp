#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int kDistinctChar(string& s, int k) {
  unordered_map<int, int> mpp;
  int i=0, j =0, n = s.size(), maxLen = 0;

  while(j<n){
    mpp[s[j]]++;
    if(mpp.size()>k){
      mpp[s[i]]--;
      if(mpp[s[i]]==0)
        mpp.erase(s[i]);
      i++;
    }
    maxLen = max(maxLen, j - i + 1);
    j++;
  }
  return maxLen;
}
