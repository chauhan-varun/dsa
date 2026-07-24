#include <bits/stdc++.h>
using namespace std;

string minWindow(string &s1, string &s2) {
  int i = 0, n = s1.size(), m = s2.size();
  string ans = "";

  while (i < n) {
    int j = 0;
    while (i < n && j < m) {
      if (s1[i] == s2[j])
        j++;
      i++;
    }
    if (j < m)
      break;

    int end = i;
    j = m - 1;

    while (j >= 0) {
      i--;
      if (s1[i] == s2[j])
        j--;
    }

    if (ans.empty() || end - i < ans.size()) {
      ans = s1.substr(i, end - i);
    }
  }
  return ans;
}
