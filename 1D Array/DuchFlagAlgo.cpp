#include<bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

void sortt(vector<int> &arr){
  int low=0, mid =0, hi = arr.size()-1;
  while(mid<=hi){
    if(arr[mid]==0) {
      swap(arr[low], arr[mid]);
      mid++; low++;
    } else if(arr[mid]==1) mid++;
    else {
      swap(arr[mid], arr[hi]);
      hi--;
    }
  }
}
int main() {
  vector<int> a = {0,1,2,0,1,2,1,2,0,0,0,1};
  sortt(a);
  for(auto x: a) cout<<x<<" ";
}
