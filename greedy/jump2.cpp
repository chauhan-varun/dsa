#include <bits/stdc++.h>
using namespace std;

// int dfs(vector<int> &arr, int i, int jumps) {
//   int n = arr.size();
//   if (i >= n - 1)
//     return jumps;
//
//   int mini = INT_MAX;
//   for (int jump = 1; jump <= arr[i]; jump++) {
//     mini = min(mini, dfs(arr, i + jump, jumps + 1));
//   }
//   return mini;
// }
//
// int jump(vector<int> &arr) {
//   return dfs(arr, 0, 0);
// }

// int dfs(vector<int> &arr, int i, int jumps, vector<vector<int>> &dp) {
//   int n = arr.size();
//
//   if (i >= n - 1)
//     return jumps;
//
//   if (dp[i][jumps] != -1)
//     return dp[i][jumps];
//
//   int mini = INT_MAX;
//   for (int jump = 1; jump <= arr[i]; jump++) {
//     mini = min(mini, dfs(arr, i + jump, jumps + 1, dp));
//   }
//   return dp[i][jumps] = mini;
// }
// int jump(vector<int> &arr) {
//   int n = arr.size();
//
//   vector<vector<int>> dp(n, vector<int>(n, -1));
//   return dfs(arr, 0, 0, dp);
// }



int jump(vector<int> &arr){
  int l = 0, r = 0, jumps = 0, n = arr.size(); 
  while(r < n-1){
    int farthest = 0;

    for(int i = l; i<=r; i++){
      farthest = max(farthest, i + arr[i]);
    }

    l = r + 1;
    r = farthest;
    jumps++;
  }
  return jumps;
}
