#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x) {
  int n = arr.size(), i = 0;
  int j = n - 1, ans = n;
  while (i <= j) {
    int mid = (i+j)/2;
    if(arr[mid]<=x){
      ans = mid;
      i = mid + 1;
    } else j = mid-1;
  }
  return ans;
}

int lowerBound(vector<int> &arr, int x) {
  int n = arr.size(), i = 0;
  int j = n - 1, ans = n;
  while (i <= j) {
    int mid = (i+j)/2;
    if(arr[mid]>x){
      ans = mid;
      j = mid -1;
    } else i = mid+1;
  }
  return ans;
}


int main() {
  vector<int> arr = {1,2,3,4,5,6,6,8,9};
  cout<<lowerBound(arr, 7);
}
