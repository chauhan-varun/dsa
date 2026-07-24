#include <bits/stdc++.h>
using namespace std;
int minPlatform(vector<int> &arr, vector<int> &dep) {
  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());

  int i = 0, j = 0, intersection = 0, n = arr.size(), cnt = 0;

  while (i < n && j < n) {
    if (arr[i]<=dep[j]) {
      cnt++;
      i++;
    } else{
      j++;
      cnt--;
    }
    intersection = max(intersection, cnt);
  }
  return intersection;
}
