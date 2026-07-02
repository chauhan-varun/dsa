#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& bt) {
  int n = bt.size();
  sort(bt.begin(), bt.end());
  int ans = 0, prev = 0;

  for(int i=1; i<n; i++){
    prev+=bt[i];
    ans+=prev;
  }
  return ans;
}
