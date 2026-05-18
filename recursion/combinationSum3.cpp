#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> res;
  vector<int> temp;
  function<void(int, int, int)> backtrack = [&](int i, int p, int q) {
    if (p < 0 || q < 0)
      return;

    if (p == 0 && q == 0) {
      res.push_back(temp);
      return;
    }

    for (int j = i; j <= 9; j++) {
      temp.push_back(j);
      backtrack(j + 1, p - j, q - 1);
      temp.pop_back();
    }
  };
  backtrack(1, n, k);
  return res;
}
