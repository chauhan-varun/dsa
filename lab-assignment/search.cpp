#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lSearch(vector<int> &arr, int x){
  
  for(int e: arr) {
    if(e==x) {
      return true;
    }
  }
  return false;
}

int bs(vector<int> &arr, int x){
  int i = 0, j = arr.size() -1;

  while(i<=j){
    int mid = (i+j)/2;
    if(x == arr[mid]) return mid;
    else if(x<arr[mid]) j = mid -1;
    else i = mid + 1;
  }
  return -1;
}
int main() {
  vector<int> arr = {1,2,3,4,5,6,9};
  cout<< bs(arr, 6);
}
