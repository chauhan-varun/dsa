#include <bits/stdc++.h>
#include <vector>
using namespace std;
int findAllSubArrWithGivenSum(pmr::vector<int> arr, int k) {
  int n = arr.size(), count = 0, prefixSum = 0;
  unordered_map<int, int> mp;
  mp[0] = 1; // Initialize with sum 0 occurring once
  for (int i = 0; i < n; i++) {
    prefixSum += arr[i];
    int rem = prefixSum - k;
    count += mp[rem];
    mp[prefixSum]++;
  }
  return count;
}
