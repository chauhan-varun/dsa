#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int arr[n+1][m+1];

  while (m--) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
  }
  return 0;
}
