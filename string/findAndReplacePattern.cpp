#include <bits/stdc++.h>
using namespace std;
string createMpp(string s) {
  char mpp[1000] = {0};
  char temp = 'a';
  for (auto ch : s) {
    if (mpp[ch] == 0) {
      mpp[ch] = temp++;
    }
  }
  for (auto ch : s) {
    ch = mpp[ch];
  }
  return s;
}

vector<string> findAndReplacePattern(vector<string> &w, string p) {
  vector<string> ans;

  string a = createMpp(p);
  for (string s: w) {
    if (a == createMpp(s)) {
      ans.push_back(s);
    }
  }
  return ans;
}
