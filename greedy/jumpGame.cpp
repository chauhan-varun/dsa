#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
bool canJump(vector<int> &arr) {
  if (arr.size() == 1)
    return true;
  int maxIdx = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (maxIdx < i)
      return false;
    maxIdx = max(maxIdx, arr[i] + i);
  }
  return true;
}

int jump(vector<int> &arr) {
  unordered_map<int, int> mpp;
  int jump = 0, maxIdx = 0;
  for(int i=0; i<arr.size(); i++){
    maxIdx = max(maxIdx, i + arr[i]);
    :

  }
}
