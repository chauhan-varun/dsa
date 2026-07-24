#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPartitions(vector<int> &arr, int diff) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if ((sum + diff) % 2 != 0)
      return 0;

    int target = (sum + diff) / 2;
    vector<char> dp(target + 1, 0);
    dp[0] = 1;

    for (int &num : arr)
      for (int k = target; k >= num; k--)
        dp[k] = dp[k] + dp[k - num];

    return dp[target];
  }
};
