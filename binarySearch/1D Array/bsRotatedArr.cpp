#include <bits/stdc++.h>
#include <vector>
using namespace std;
int bs(vector<int> &arr, int x){
  int i = 0, n = arr.size(), j = n -1;
  while(i<=j){
    int mid = i + (j -i)/2;
    if(arr[mid] == x) return mid;
    else if(arr[i] == arr[mid] and arr[j] == arr[mid]) {
      i++; j--;
    }
    else if(arr[i]<=arr[mid]){ // sorted first half
      if(arr[i]<=x && x<=arr[mid]) j = mid -1;
      else i = mid + 1;
    } else if(arr[mid]<=arr[j]){ // sorted second half
      if(arr[mid]<=x && arr[j]>=x) i = mid + 1;
      else j = mid - 1;
    }
  }
  return -1;
}
