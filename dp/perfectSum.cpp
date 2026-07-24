#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  int perfectSum(vector<int> &arr, int target) {
    int n = arr.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int &num : arr) {
      for (int k = target; k >= num; k--) {
        dp[k] = dp[k] + dp[k - num];
      }
    }
    return dp[target];
  }
};
