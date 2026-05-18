#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& arr) {
  int n = arr.size();
  int subsets = (1<<n);
  vector<vector<int>> ans;

  for(int i=0; i< subsets; i++){
    vector<int> temp;
    for(int j=0; j<n; j++){
      if(i&(1<<j)) 
        temp.push_back(arr[j]);
    }
    ans.push_back(temp);
  }
  return ans;
}
vector<vector<int>> subset(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> ans;
  vector<int> v;

  function<void(int)> dfs = [&](int i){
    if(i==n){
      ans.push_back(v);
      return;
    }
    if(i>n) return;
    v.push_back(arr[i]);
    dfs(i+1);
    v.pop_back();
    dfs(i+1);
  };
  return ans;
}


