#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i, int j, int n, vector<string> &res) {

  int p = i, q = j;

  while (q >= 0 && p >= 0) {
    if (res[p--][q--] == 'Q')
      return false;
  }

  p = i, q = j;
  while (q >= 0) {
    if (res[p][q--] == 'Q')
      return false;
  }

  p = i, q = j;
  while (p < n && q >= 0) {
    if (res[p++][q--] == 'Q')
      return false;
  }
  return true;
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> res;
  vector<string> temp(n);
  string s(n, '.');

  for (string &str : temp) {
    str = s;
  }

  function<void(int)> dfs = [&](int j) {
    if (j == n) {
      res.push_back(temp);
      return;
    }

    for (int row = 0; row < n; row++) {
      if (isSafe(row, j, n, temp)) {
        temp[row][j] = 'Q';
        dfs(j + 1);
        temp[row][j] = '.';
      }
    }
  };

  dfs(0);
  return res;
}
