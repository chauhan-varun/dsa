#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dfs(vector<int> &ht, int i, int &k, vector<int> &dp) {
    if (i == 0)
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int steps = INT_MAX;
    for (int j = 1; j <= k; j++) {
      if (i >= j) {
        steps = min(steps, dfs(ht, i - j, k, dp) + abs(ht[i] - ht[i - j]));
      }
    }
    return dp[i] = steps;
  }

public:
  int frogJump(vector<int> &heights, int k) {

    if (heights.empty())
      return 0;
    int n = heights.size();

    vector<int> dp(n, -1);
    return dfs(heights, n - 1, k, dp);
  }
};

class tabulation {
  int frogJump(vector<int> &heights, int k) {
    int n = heights.size();
    if (n == 0)
      return 0;

    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
      int steps = INT_MAX;
      for (int j = 1; j <= k; j++) {
        if (i >= j)
          steps = min(steps, dp[i - j] + abs(heights[i] - heights[i - j]));
      }
      dp[i] = steps;
    }
    return dp[n - 1];
  }
};

class spaceOp {
  int frogJump(vector<int> &heights, int k) {
    int n = heights.size();
    if (n == 0)
      return 0;

    vector<int> dp(k, 0);
    for (int i = 1; i < n; i++) {
      int steps = INT_MAX;
      for (int j = 1; j <= k; j++) {
        if (i >= j)
          steps = min(steps, dp[(i-j)%k] + abs(heights[i] - heights[i - j]));
      }
      dp[i%k] = steps;
    }
    return dp[(n-1)%k];
  }
};
