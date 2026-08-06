#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> duplicates(vector<int> &arr){
  unordered_map<int, int> mpp;
  set<int> st;
  for(int i : arr) {
    mpp[i]++;
    if(mpp[i] > 1) st.insert(i);
  }

  return vector<int> (st.begin(), st.end());
}

int main() {
  vector<int> arr = {1,2,2,3,4,4,4,5,5,5,6,6,7};
  vector<int> ans = duplicates(arr);
  for(int i : ans) cout<<i<<" ";
}
