#include <bits/stdc++.h>
using namespace std;

class Solution {
  int kmp(const string &s) {
    int n = s.size();
    int prefixIdx = 0;
    int suffixIdx = 1;

    vector<int> lps(n, 0);

    while (suffixIdx < n) {
      if (s[prefixIdx] == s[suffixIdx]) {
        lps[suffixIdx++] = ++prefixIdx;
      } else if (prefixIdx == 0) {
        suffixIdx++;
      } else {
        prefixIdx = lps[prefixIdx - 1];
      }
    }

    return lps[n - 1];
  }

public:
  int minChar(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    string combined = s + "#" + reversed;
    int longestPalindromicSubsequence = kmp(combined);

    return s.size() - longestPalindromicSubsequence;
  }
};
