#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int odd = 0, even = 0, pos = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      even++;
    } else {
      odd++;
    }

    if (x > 0) {
      pos++;
    } else if (x < 0) {
      neg++;
    }
  }
  cout << "Even: " << even << '\n';
  cout << "Odd: " << odd << '\n';
  cout << "Positive: " << pos << '\n';
  cout << "Negative: " << neg << '\n';

  return 0;
}
