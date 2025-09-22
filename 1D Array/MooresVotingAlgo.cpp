#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int MooreVotingAlgo(vector<int> &arr) {
  int count = 0, x, n = arr.size();
  for (int i = 0; i < n; i++) {
    if (count == 0) {
      x = arr[i];
      count = 1;
    } else if (x == arr[i]) {
      count++;
    } else {
      count--;
    }
  }
  count=0;
  for(int i=0;i<n;i++){
    if(arr[i]==x) count++;
  }
  if(count>n/2) return x;
  return -1;
}

int main() {
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  cout << MooreVotingAlgo(arr) << endl;
}
