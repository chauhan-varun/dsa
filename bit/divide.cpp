#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor) {
  if (dividend == divisor)
    return 1;
  if(dividend == INT_MIN && divisor ==-1 ) return INT_MAX;
  if(divisor == 1) return dividend;

  int sign = 1;
  if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    sign = -1;

  long n = abs(dividend), d = abs(divisor);
  long ans = 0;

  while (n >= d) {
    int count = 0;
    while (n > (d << (count + 1))) {
      count++;
      ans+=(1<<count);
      n = n - (d << count);
    }
  }
  return sign * ans;
}
