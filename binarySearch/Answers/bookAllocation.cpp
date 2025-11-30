#include <bits/stdc++.h>
#include <numeric>
#include <unistd.h>
using namespace std;
int allocate(vector<int> &arr, int m) {
  int student = 1, pages = 0;
  for(int i=0; i<arr.size(); i++){
    if(pages + arr[i]<=m){
      pages+=arr[i];
    } else {
      student++;
      pages = arr[i];
    }
  }
  return student;
}
int findPages(vector<int> &arr, int k) {
  if(k>arr.size()) return -1;
  int i = *max_element(arr.begin(), arr.end());
  int j = accumulate(arr.begin(), arr.end(), 0);

  while (i <= j) {
    int m = i + (j - i) / 2;
    if (allocate(arr, m)<=k)
      j = m - 1;
    else
      i = m + 1;
  }
  return i;
}
