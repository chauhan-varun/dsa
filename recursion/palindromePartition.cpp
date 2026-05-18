#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int i, int j) {
  while (i < j) {
    if (s[i++] != s[j--])
      return false;
  }
  return true;
}
vector<vector<string>> partition(string s) {
  vector<vector<string>> res;
  vector<string> path;
  int n = s.size();

  function<void(int)> backtrack = [&](int i) {
    if (i == n) {
      res.push_back(path);
      return;
    }

    for (int j = i; j < n; j++) {
      if (isPalindrome(s, i, j)) {
        path.push_back(s.substr(i, j - i +1));
        backtrack(j + 1);
        path.pop_back();
      }
    }
  };
  
  backtrack(0);
  return res;
}
