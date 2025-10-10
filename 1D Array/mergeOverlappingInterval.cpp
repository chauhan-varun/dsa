#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr) {
  // sort
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    int start = arr[i][0];
    int end = arr[i][1];
    if (!ans.empty() && end <= ans.back()[1])
      continue;

    for (int j = 0; j < n; j++) {
      if (arr[j][0] <= end) {
        end = max(end, arr[j][1]);
      } else
        break;
    }
    ans.push_back({start, end});
  }
  return ans;
}

vector<vector<int>> mergeOverlaping(vector<vector<int>> &arr) {
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (ans.empty() || arr[i][0] > ans.back()[1]) {
      ans.push_back({arr[i][0], arr[i][1]});
    } else {
      ans.back()[1] =  max(arr[i][1], ans.back()[1]);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
  vector<vector<int>> ans = mergeOverlaping(arr);
  cout << "The merged intervals are: " << "\n";
  for (auto it : ans) {
    cout << "[" << it[0] << ", " << it[1] << "] ";
  }
  cout << endl;
  return 0;
}
