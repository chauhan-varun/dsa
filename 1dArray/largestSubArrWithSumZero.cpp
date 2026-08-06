#include <bits/stdc++.h>
#include <vector>
using namespace std;
int largest(vector<int> &arr) {
  int n = arr.size(), maxLen = 0;
  long long sum = 0;

  map<long long, int> mpp;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == 0) {
      maxLen = max(maxLen, i + 1);
    }

    if (mpp.find(sum) != mpp.end()) {
      int j = mpp[sum];
      maxLen = max(maxLen, j - i);
    } else {
      mpp[sum] = i;
    }
  }
  return maxLen;
}
