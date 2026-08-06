#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getLIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int li = 0, maxi = 1;

    for (int i = 0; i < n; i++) {
      hash[i] = i;
      for (int pi = 0; pi < i; pi++) {
        if (arr[pi] < arr[i] && dp[i] < 1 + dp[pi]) {
          dp[i] = 1 + dp[pi];
          hash[i] = pi;
        }
      }
      if (dp[i] > maxi) {
        maxi = dp[i];
        li = i;
      }
    }

    vector<int> ans(maxi);
    int i = maxi -1;
    while(hash[li]!=li){
      ans[i--] = arr[li];
      li = hash[li];
    }
    ans[i] = arr[li];
    return ans;
  }
};
