#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

int split(vector<int>&arr, int parts){
  int noOfArr = 1, sum = 0;
  for(int i = 0; i<arr.size(); i++){
    if(sum+arr[i]<=parts){
      sum+=arr[i];
    }else {
      noOfArr++;
      sum = 0;
    }
  }
  return noOfArr;
}
int splitArray(vector<int> &arr, int k) {
  int i = *max_element(arr.begin(), arr.end());
  int j = accumulate(arr.begin(), arr.end(), 0);
  while (i <= j) {
    int m = (i+j)/2;
    if(split(arr, m)>k) i = m + 1;
    else j = m -1;
  }
  return i;
}
