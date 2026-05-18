#include <bits/stdc++.h>
#include <functional>
using namespace std;

bool validParanthesis(string s) {
  int min = 0, max = 0;
  for (char c : s) {
    if (c == '(') {
      min++;
      max++;
    } else if (c == ')') {
      min--;
      max--;
    } else {
      min--;
      max++;
    }
    if (min < 0)
      min = 0;
    if (max < 0)
      return false;
  }
  return min == 0;
}

bool dfs(string s, int i, int cnt) {
  if (cnt < 0)
    return false;
  if (i == s.size())
    return cnt == 0;

  if (s[i] == '(')
    return dfs(s, i + 1, cnt + 1);
  else if (s[i] == ')')
    return dfs(s, i + 1, cnt - 1);
  else {
    return (dfs(s, i + 1, cnt + 1) or dfs(s, i + 1, cnt - 1) or
            dfs(s, i + 1, cnt));
  }
}

bool validParantesiss(string s) {
  return dfs(s, 0, 0);
}
