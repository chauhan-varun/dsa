#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(vector<int> &arr, int i, vector<vector<int>> &ans, vector<int> &temp) {
  if (i >= (int)arr.size()) {
    ans.push_back(temp);
    return;
  }

  temp.push_back(arr[i]);
  dfs(arr, i + 1, ans, temp);
  temp.pop_back();

  dfs(arr, i + 1, ans, temp);
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  vector<vector<int>> ans;
  vector<int> temp;

  dfs(arr, 0, ans, temp);

  for (auto &v : ans) {
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
