#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<int> &heights) {
    if (heights.empty())
      return 0;

    int n = heights.size();
    int prev1 = 0, prev2 = 0;

    for (int i = 1; i < n; i++) {
      int one = prev1 + abs(heights[i] - heights[i - 1]);
      int two = INT_MAX;
      if (i > 1)
        two = prev2 + abs(heights[i] - heights[i - 2]);

      int curr = min(one, two);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};
