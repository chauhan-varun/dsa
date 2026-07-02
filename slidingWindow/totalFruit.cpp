#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// int totalFruit(vector<int> &fruits) {
//   unordered_map<int, int> mpp;
//   int i = 0, j = 0, n = fruits.size(), maxLen = 0;
//
//   while (j < n) {
//     mpp[fruits[j]]++;
//     while (mpp.size() >= 2) {
//       mpp[fruits[i]]--;
//       if (mpp[fruits[i]] == 0)
//         mpp.erase(fruits[i]);
//       i++;
//     }
//     maxLen = max(maxLen, j - i + 1);
//     j++;
//   }
//   return maxLen;
// }
int totalFruit(vector<int> &fruits) {
  unordered_map<int, int> mpp;
  int i = 0, j = 0, n = fruits.size(), maxLen = 0;

  while (j < n) {
    mpp[fruits[j]]++;
    if(mpp.size() >= 2) {
      mpp[fruits[i]]--;
      if (mpp[fruits[i]] == 0)
        mpp.erase(fruits[i]);
      i++;
    }
    maxLen = max(maxLen, j - i + 1);
    j++;
  }
  return maxLen;
}

