  #include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

ll fib(vector<ll> &dp, ll n) {
  if (n <= 1)
    return 0;
  if (n == 2)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = fib(dp, n - 1) + fib(dp, n - 2);
}
int main() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, -1);
  cout << fib(dp, n) << endl;
  return 0;
}
