#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n) {
  int sum = accumulate(arr.begin(), arr.end(), 0);
  vector<char> dp(sum + 1, 0);
  dp[0] = 1;

  for (int &num : arr) {
    for (int x = sum; x >= num; x--) {
      dp[x] = dp[x] or dp[x - num];
    }
  }

  for (int x = sum / 2; x >= 0; x--) {
    if (dp[x])
      return sum - 2 * x;
  }
  return sum;
}
