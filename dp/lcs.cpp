#include <bits/stdc++.h>
#include <vector>
using namespace std;

string findLCS(int n, int m, string &s, string &t) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int len = dp[n][m];
  int idx = len - 1;
  string ans(len, '#');

  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans[idx--] = s[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] < dp[i][j - 1])
      j--;
    else
      i--;
  }
  return ans;
}
