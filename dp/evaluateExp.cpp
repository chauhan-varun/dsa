#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000000007;

int evaluateExp(string &s) {
  int n = s.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
  for (int i = n - 1; i >= 0; i -= 2) {
    dp[i][i][1] = (s[i] == 'T');
    dp[i][i][0] = 1;
    for (int j = i + 1; j < n; j += 2) {
      for (int flag = 0; flag <= 1; flag++) {
        ll ways = 0;
        for (int idx = i + 1; idx <= j - 1; idx += 2) {
          ll lt = dp[i][idx - 1][1];
          ll lf = dp[i][idx - 1][0];
          ll rt = dp[idx + 1][j][1];
          ll rf = dp[idx + 1][j][0];

          if (s[idx] == '&') {
            if (flag)
              ways = (ways + (lt * rt) % MOD) % MOD;
            else
              ways =
                  (ways + (lf * rt) % MOD + (lt * rf) % MOD + (rf * lf) % MOD) %
                  MOD;

          } else if (s[idx] == '|') {
            if (flag)
              ways =
                  (ways + (lt * rf) % MOD + (lf * rt) % MOD + (lt * rt) % MOD) %
                  MOD;
            else
              ways = (ways + (lf * rf) % MOD);
          }

          else {
            if (flag)
              ways = (ways + (lt * rf) % MOD + (lf * rt) % MOD) % MOD;
            else
              ways = (ways + (lt * rt) % MOD + (lf * rf) % MOD) % MOD;
          }
        }
        dp[i][j][flag] = ways;
      }
    }
  }
  return dp[0][n - 1][1];
}
