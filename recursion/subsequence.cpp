#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int k,
         int i, int sum) {
  if (i >= arr.size()) {
    if (k == sum)
      ans.push_back(temp);
    return;
  }

  temp.push_back(arr[i]);
  dfs(arr, temp, ans, k, i + 1, sum + arr[i]);
  temp.pop_back();

  dfs(arr, temp, ans, k, i + 1, sum);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  vector<int> temp;
  vector<vector<int>> ans;
  int sum = 0;
  dfs(arr, temp, ans, 4, sum, 0);

  for (auto &v : ans) {
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
