#include <bits/stdc++.h>
#include <functional>
#include <unordered_set>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> wd(wordDict.begin(), wordDict.end());

  function<bool(int, int)> find = [&](int i, int j) {
    if (j == s.length() - 1) {
      if (wd.count(s.substr(i, j - i + 1)))
        return true;
      return false;
    }

    if (wd.count(s.substr(i, j - i + 1))) {
      if (find(j + 1, j + 1))
        return true;
    }
    return find(i, j + 1);
  };
  return find(0, 0);
}
