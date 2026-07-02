#include <bits/stdc++.h>
using namespace std;
// int numSubarraysWithSum(vector<int> &arr, int x) {
//   int c = 0, n = arr.size(), i = 0, sum = 0;
//   unordered_map<int, int> mpp;
//   mpp[0] = 1;
//   while (i < n) {
//     sum += arr[i];
//     if (mpp.find(sum - x) != mpp.end()) {
//       c+=mpp[sum - x];
//     }
//     mpp[sum]++;
//     i++;
//   }
//   return c;
// }
