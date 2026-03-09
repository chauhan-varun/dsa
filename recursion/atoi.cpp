#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int convert(int i, const string &s, long long ans, int sign) {
  if (i >= s.size() || !isdigit(s[i]))
    return sign * ans;

  ans = ans * 10 + s[i] - '0';
  if (sign * ans >= INT_MAX)
    return INT_MAX;
  if (sign * ans <= INT_MIN)
    return INT_MIN;

  return convert(i+1, s, ans, sign);
}

int myAtoi(string s) {
  int sign = 1;
  int i = 0, n = s.size();
  while (i < n && s[i] == ' ')
    i++;
  if (i < n && (s[i] == '-' || s[i] == '+')) {
    if (s[i] == '-')
      sign = -1;
    i++;
  }
  if (i >= n || !isdigit(s[i]))
    return 0;
  return convert(i, s, 0LL, sign);
}
