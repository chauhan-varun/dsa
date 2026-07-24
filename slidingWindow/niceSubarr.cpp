#include <bits/stdc++.h>
#include <vector>
using namespace std;

int niceSubarr(vector<int> &arr, int k){
  int i=0, j =0, n = arr.size(), cnt = 0, odd = 0;

  while(j<n){
    if(arr[j]%2)
      odd++;
    if(odd>k){
      if(arr[i]%2)
        odd--;
      i++;
    }
    cnt+=(j - i + 1);
    j++;
  }
  return cnt;
}
int numberOfSubarrays(vector<int>& arr, int k) {
  return niceSubarr(arr, k) - niceSubarr(arr, k-1);
}
