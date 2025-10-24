#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int bs(vector<int> &arr){
  int i = 0, j = arr.size() -1;
  int mini = INT_MAX;
  while(i<=j){
    int mid = (i+j)/2;
    if(arr[i]<=arr[j]){
      mini = min(mini, arr[i]);
      break;
    }
    if(arr[i]<=arr[mid]){
      mini = min(mini, arr[i]);
      i = mid + 1;
    } else if(arr[mid]<=arr[j]){
      mini = min(mini, arr[mid]);
      j = mid -1;
    }
  }
  return mini;
}
