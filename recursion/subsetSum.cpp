#include <bits/stdc++.h>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, vector<int> &ans, int sum, int i) {
  if (i == arr.size()) {
    ans.push_back(sum);
    return;
  }

  subsetSum(arr, ans, sum+arr[i], i + 1);
  subsetSum(arr, ans, sum, i + 1);
}

int main() {
  vector<int> arr = {3, 1, 2};
  vector<int> ans;
  subsetSum(arr, ans, 0, 0);
  for (int x : ans)
    cout << x << " ";
}
