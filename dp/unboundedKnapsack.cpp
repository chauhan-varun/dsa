#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < val.size(); i++) {
      for (int cap = wt[i]; cap <= capacity; cap++) {
        dp[cap] = max(dp[cap], val[i] + dp[cap - wt[i]]);
      }
    }
    return dp[capacity];
  }
};
