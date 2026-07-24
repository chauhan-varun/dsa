#include <bits/stdc++.h>
#include <numeric>
#include <utility>
using namespace std;
bool dfs(vector<vector<int>> &dp, vector<int> &arr, int i, int target) {
  if (target == 0)
    return 1;

  if (i == 0)
    return target == arr[0];

  if (dp[i][target] != -1)
    return dp[i][target];

  bool pick = target >= arr[i] ? dfs(dp, arr, i - 1, target - arr[i]) : 0;
  bool notPick = dfs(dp, arr, i - 1, target);

  return dp[i][target] = pick or notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
  if (n == 0)
    return k == 0;

  vector<char> dp(k + 1, 0);

  dp[0] = true;

  for (int &num : arr) {
    for (int target = k; target >= num; target--) {
      dp[target] = dp[target - num] or dp[target];
    }
  }
  return dp[k];
}
