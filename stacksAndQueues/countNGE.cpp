#include <bits/stdc++.h>
#include <iterator>
#include <set>
#include <vector>
using namespace std;
vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
  vector<int> res;
  int n = arr.size();
  vector<int> greaterCount(n,0);
  multiset<int> seen;
  
  for(int i=n-1; i>=0; i--){
    auto it = seen.upper_bound(arr[i]);
    greaterCount[i] = distance(it, seen.end());
    seen.insert(arr[i]);
  }

  for(int x: indices){
    res.push_back(greaterCount[x]);
  }
  return res;
}
