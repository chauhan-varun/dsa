#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  int longestBitonicSequence(int n, vector<int> &arr) {
    vector<int> lis(n, 1), lds(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++) {
      int r = n - 1 - i;
      for (int pi = 0; pi < i; pi++) {
        if (arr[pi] < arr[i])
          lis[i] = max(lis[i], 1 + lis[pi]);

        int next = n - 1 - pi;
        if (arr[next] < arr[r])
          lds[r] = max(lds[r], 1 + lds[next]);
      }
    }

    for (int i = 0; i < n; i++)
      if (lis[i] > 1 && lds[i] > 1)
        maxi = max(maxi, lis[i] + lds[i] - 1);

    return maxi;
  }
};
