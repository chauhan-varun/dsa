#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  int dfs(vector<vector<int>> &dp, vector<int> &price, int i, int len) {
    if (len == 0)
      return 0;

    if (i == 0) {
      return len * price[0];
    }

    if (dp[i][len] != -1)
      return dp[i][len];

    int pick = i + 1 <= len ? price[i] + dfs(dp, price, i, len - i - 1) : 0;
    int notPick = dfs(dp, price, i - 1, len);

    return dp[i][len] = max(pick, notPick);
  }

public:
  int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> dp(n + 1, 0);

    for (int len = 0; len <= n; len++)
      dp[len] = len * price[0];

    for (int i = 1; i < n; i++) {
      for (int len = 1; len <= n; len++) {
        int pick = i + 1 <= len ? price[i] + dp[len - i - 1] : 0;
        int notPick = dp[len];

        dp[len] = max(pick, notPick);
      }
    }
    return dp[n];
  }
};
