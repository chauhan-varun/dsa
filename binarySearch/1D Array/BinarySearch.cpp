#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> &arr, int x) {
  sort(arr.begin(), arr.end());
  int n = arr.size(), i = 0;
  int j = n - 1;
  while (i < j) {
    int mid = (i+j)/2;
    if(arr[mid]>x){
      j = mid -1;
    } else if(arr[mid]<x){
      i = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  cout<<bs(arr, 8);
}
