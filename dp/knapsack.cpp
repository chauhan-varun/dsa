#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dfs(vector<vector<int>> &dp, vector<int> &val, vector<int> &wt, int w,
          int i) {
    if(i==0){
      if(wt[0]<=w)
        return val[0];
      return 0;
    }

    if (dp[i][w] != -1)
      return dp[i][w];

    int pick =
        wt[i] <= w ? val[i] + dfs(dp, val, wt, w - wt[i], i - 1) : INT_MIN;
    int notPick = dfs(dp, val, wt, w, i - 1);

    return dp[i][w] = max(pick, notPick);
  }

public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    if (n == 0 || W == 0)
      return 0;
    vector<int> dp(W + 1, 0);
    for (int w = wt[0]; w <= W; w++)
      dp[w] = val[0];

    for (int i = 1; i < n; i++) {
      for (int w = W; w >= wt[i]; w--) {
        int notPick = dp[w];
        int pick = val[i] + dp[w - wt[i]];

        dp[w] = max(pick, notPick);
      }
    }
    return dp[W];
  }
};
