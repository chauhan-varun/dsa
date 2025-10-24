#include <bits/stdc++.h>
#include <vector>
using namespace std;
int peakEle(vector<int> &arr){
  int n = arr.size();
  int i = 1, j = n-2;
  while(i<=j){
    int mid = (i+j)/2;
    if(arr[mid]<arr[mid+1]) i = mid + 1;
    else j = mid  - 1;
  }
  if(arr[i]>arr[j]) return i;
  return j;
}

int main(){
  vector<int> arr = {5,6,5,4,3,2,1};
  cout<<peakEle(arr);
}
