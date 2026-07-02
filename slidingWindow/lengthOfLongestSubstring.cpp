#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// int lengthOfLongestSubstring(string s) {
//   int maxLen = 0, n = s.size();
//   for (int i = 0; i < n; i++) {
//     bool hash[256] = {0};
//     for (int j = 0; j < n; j++) {
//       if (hash[s[j]] != 0) {
//         break;
//       }
//       maxLen = max(maxLen, j - i + 1);
//       hash[s[j]] = 1;
//     }
//   }
//   return maxLen;
// }

int lengthOfLongestSubstring(string s) {
  int i = 0, j = 0, n = s.size(), maxLen = 0;
  unordered_map<int, int> mpp;
  while (j < n) {
    if(mpp.find(s[j])!=mpp.end() && mpp[s[j]] >= i){
      i = mpp[s[j]] + 1;
    }
    mpp[s[j]]=j;
    maxLen = max(maxLen, j - i +1);
    j++;
  }
  return maxLen;
}
