#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> KadanesAlgo(vector<int> &arr) {
  int maxSum =INT_MIN, sum = 0, n = arr.size(), x = -1, y = -1, start;
  for(int i=0; i<n; i++){
    if(sum == 0 ) {
      start = i;
    }
    sum+=arr[i];
    if(sum>maxSum){
      maxSum = sum;
      x = start;
      y = i;
    }
    if(sum<0){
      sum = 0;
    }
  }
  return {x , y};
}

int main() {
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> ans = KadanesAlgo(arr);
  cout << ans[0] << " " << ans[1];
}
