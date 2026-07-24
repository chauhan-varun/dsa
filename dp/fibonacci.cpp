#include <bits/stdc++.h>
#include <vector>
using namespace std;

// memoisation
int fib(int n, vector<int> &dp) {
  if (n <= 1)
    return n;

  if (dp[n] != -1)
    return dp[n];

  return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fibonacci(int n) {
  vector<int> dp(n + 1, -1);
  return fib(n, dp);
}

// tabutation
int fibonaci(int n) {
  if (n <= 1)
    return n;

  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}
// space optimisation
int fibonaccii(int n) {
  if (n <= 1)
    return n;
  int prev1 = 1, prev2 = 0; 
  for (int i = 2; i <= n; i++) {
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}
