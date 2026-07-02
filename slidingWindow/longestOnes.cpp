#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k) {
  int i = 0, j = 0, maxLen = 0, n = nums.size(), c = 0;

  while (j < n) {
    if (nums[j] == 0)
      c++;
    if(c > k){
      if(nums[i] == 0) 
        c--;
      i++;
    } 
    
    maxLen = max(maxLen, j - i + 1);
    j++;
  }
  return maxLen;
}
