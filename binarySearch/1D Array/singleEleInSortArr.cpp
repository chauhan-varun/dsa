#include <bits/stdc++.h>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int> &arr) {

  int i = 0, j = arr.size() - 1;
  while (i < j) {
    int mid = (i + j) / 2;
    // Ensure mid is even
    if (mid % 2 == 1)
      mid--;
    if (arr[mid] == arr[mid + 1])
      i = mid + 2;
    else
      j = mid;
  }
  return arr[i];
}

int singleNonDup(vector<int> &arr){
  int n = arr.size();
  int i = 1, j = n -2;
  
  if(n == 1) return arr[0];
  if(arr[i]!=arr[i-1]) return arr[i-1];
  if(arr[n-1]!=arr[n-2]) return arr[n-1];
  
  while(i<=j){
    int mid = (i+j)/2;
    if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]) return arr[mid];
    else if((mid%2==1 && arr[mid]==arr[mid-1]) or (mid%2==0 and arr[mid+1]==arr[mid])){
      i = mid + 1;
    }else j = mid -1;
  }
  return -1;
}
