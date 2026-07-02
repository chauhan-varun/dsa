#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// int characterReplacement(string s, int k) {
//   int n = s.size(), maxLen = 0;
//
//   for (int i = 0; i < n; i++) {
//     int hash[26] = {0};
//     int maxFreq = 0;
//     for (int j = i; j < n; j++) {
//       hash[s[j] - 'A']++;
//       maxFreq = max(maxFreq, hash[s[j] - 'A']);
//       int changes = (j - i + 1) - maxFreq;
//       if (changes <= k)
//         maxLen = max(maxLen, j - i + 1);
//     }
//   }
//   return maxLen;
// }
int characterReplacement(string s, int k) {
  int n = s.size(), maxLen = 0, i = 0, j = 0, maxFreq = 0;
  unordered_map<int, int> mpp;

  while (j < n) {
    mpp[s[j]]++;
    maxFreq = max(maxFreq, mpp[s[j]]);
    if ((j - i + 1) - maxFreq > k) {
      mpp[s[i]]--;
      maxFreq = 0;
      i++;
    }
    maxLen = max(maxLen, j - i + 1);
    j++;
  }
  return maxLen;
}
