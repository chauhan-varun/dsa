#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr){
  int i = 0, j = arr.size() -1, idx = -1;
  int mini = INT_MAX;
  while(i<=j){
    int mid = (i+j)/2;
    if(arr[i]<=arr[j]){
      if(arr[i]<=mini){
        mini = arr[i];
        idx = i;
      }
      break;
    }
    if(arr[i]<=arr[mid]){
      if(arr[i]<=mini){
        mini = arr[i];
        idx = i;
      }
      i = mid + 1;
    } else if(arr[mid]<=arr[j]){
      if(arr[mid]<=mini){
        mini = arr[mid];
        idx = mid;
      }
      j = mid -1;
    }
  }
  return idx;
}
int main() {
  vector<int> arr = {5,1,2,3,4};
  cout<<findKRotation(arr);
}
