#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> mergeOverlaping(vector<vector<int>> &arr) {
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  int n = arr.size();

  for (int i = 0; i < n;) {
    int st = arr[i][0], end = arr[i][1];

    int j = i + 1;
    while ( j < n && arr[j][0] <= end){ 
      end = max(end, arr[j][1]);
      j++;
    }
    ans.push_back({st, end});
    i = j;
  }
  return ans;
}

vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr){
  int n = arr.size();
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  
  for(auto it: arr){
    if(ans.empty() || it[0] > ans.back()[1])
      ans.push_back(it);
    else 
      ans.back()[1] = max(ans.back()[1], it[1]);
  }
  return ans;
}
int main() {
  vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
  vector<vector<int>> ans = mergeOverlapping(arr);
  cout << "The merged intervals are: " << "\n";
  for (auto it : ans) {
    cout << "[" << it[0] << ", " << it[1] << "] ";
  }
  cout << endl;
  return 0;
}
