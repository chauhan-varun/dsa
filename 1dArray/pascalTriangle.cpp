#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> getRow(int row) {
  vector<int> arr;
  arr.push_back(1);
  long long ans = 1;
  
  for(int col =1; col<row; col++) {
    ans *= (row-col);
    ans /= col;
    arr.push_back(ans);
  }
  return arr;
}

vector<vector<int>> pascalTriangle(int n) {
  vector<vector<int>> ans; 
  for(int i=0; i<n; i++ ) {
    ans.push_back(getRow(i));
  }
  return ans;
}

int main() { return 0; }
