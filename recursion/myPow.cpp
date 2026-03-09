#include <bits/stdc++.h>
using namespace std;

double pow(double x, long long n, double ans) {

  if (n == 0)
    return ans;

  if (n % 2)
    return pow(x, n - 1, ans * x);
  else
    return pow(x * x, n / 2, ans);

  return ans;
}

double myPow(double x, int n) {
  long long nn = n;
  if (nn < 0) {
    nn = -nn;
    x = 1.0 / x;
  }
  return pow(x, nn, 1.0);
}
