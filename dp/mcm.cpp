#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  int dfs(vector<vector<int>> &dp, vector<int> &arr, int i, int j) {
    if (i == j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++) {
      int steps = arr[i - 1] * arr[k] * arr[j] + dfs(dp, arr, i, k) +
                  dfs(dp, arr, k + 1, j);
      mini = min(mini, steps);
    }

    return dp[i][j] = mini;
  }

public:
  int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 1; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = 1e9;
        for (int k = i; k < j; k++) {
          int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
          dp[i][j] = min(dp[i][j], steps);
        }
      }
    }
    return dp[1][n - 1];
  }
};
