#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int largestSubArrWithSumK(vector<int> arr, int k) {
  int maxLen = 0; long long sum = 0;
  map<long long, int> preSum;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == k)
        maxLen = max(maxLen, i+1);
    
    long long rem = sum -k;
    if (preSum.find(rem) != preSum.end()) {
      int len = i - preSum[rem];
      maxLen = max(maxLen, len);
    }
      preSum[sum] = i;
  }
  return maxLen;
}

int largestSubPositiveArrWithSumK(vector<int> arr, int k){
  int i=0, j=0, maxLen = 0, n = arr.size();
  long long sum = arr[0];

  while(j<n){
    while(i<j && sum>k){
      sum-=arr[i];
      i++;
    }
    if(sum ==k) maxLen = max(maxLen, j-i+1);
    j++;
    if(j<n) sum+=arr[j];
  }
  return maxLen;
}
int main() {
  vector<int> arr = {1,2,3,1,1,1,1};
  int k = 3;
  cout << largestSubArrWithSumK(arr, k);
}
