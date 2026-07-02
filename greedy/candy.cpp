#include <bits/stdc++.h>
#include <vector>
using namespace std;

// int candy(vector<int> &ratings) {
//   int n = ratings.size();
//   vector<int> v(1, n);
//
//   for (int i = 1; i < n; i++) {
//     if (ratings[i] < ratings[i - 1])
//       v[i] = v[i - 1] + 1;
//   }
//   int candies = 0;
//   for (int i = 1; i < n; i++) {
//     if (ratings[i] > ratings[i - 1])
//       candies+=max(v[i - 1] + 1, v[i]);
//   }
//   return candies;
// }

int candy(vector<int> &arr) {
  int n = arr.size(), ans = 1, i = 1;
  while (i < n) {
    if (arr[i - 1] == arr[i]) {
      i++;
      ans++;
      continue;
    }
    int top = 1;
    while (i < n && arr[i - 1] < arr[i]) {
      ans += top++;
      i++;
    }
    int down = 1;
    while (i < n && arr[i - 1] > arr[i]) {
      ans += down++;
      i++;
    }
    if (down > top)
      ans += (down - top);
  }
  return ans;
}
