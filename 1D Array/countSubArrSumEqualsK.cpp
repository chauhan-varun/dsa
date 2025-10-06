#include <bits/stdc++.h>
using namespace std;

int countSubArrSumEqualsK(vector<int> &arr, int k) {
  unordered_map<int, int> mpp;
  int prefixSum = 0, count = 0;
  mpp[0]++;
  for (int i = 0; i < arr.size(); i++) {

    prefixSum += arr[i];
    int x = prefixSum - k;
    count += mpp[x];
    mpp[prefixSum]++;
  }
  return count;
}

int main() {
  vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
  cout << countSubArrSumEqualsK(arr, 3);
}
