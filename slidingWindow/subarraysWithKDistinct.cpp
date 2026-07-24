#include <bits/stdc++.h>
using namespace std;

int kDistinctSubarr(vector<int>& arr, int k) {
  unordered_map<int, int> mpp;
  int i=0, j =0, n = arr.size(), cnt = 0;

  while(j<n){
    mpp[arr[j]]++;
    if(mpp.size()>k){
      mpp[arr[i]]--;
      if(mpp[arr[i]]==0)
        mpp.erase(arr[i]);
      i++;
    }
    cnt+=(j-i+1);
    j++;
  }
  return cnt;
}
int subarraysWithKDistinct(vector<int>& arr, int k) {
  return kDistinctSubarr(arr, k) - kDistinctSubarr(arr, k -1);
}
