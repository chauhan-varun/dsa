#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElements(vector<int>& arr) {
  int n = arr.size();
  vector<int> res(n);
  stack<int> st;
  for(int i=2*n-1; i>=0; i--){
    while(!st.empty() && st.top()<=arr[i%n]){
      st.pop();
    }

    if(st.empty())
      res[i%n] = -1;
    else 
      res[i%n] = st.top();

    st.push(arr[i%n]);
  }
  return res;
}
