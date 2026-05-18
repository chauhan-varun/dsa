#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
  stack<int> st;
  int n = arr.size();
  vector<int> res(n);

  for(int i=n-1; i>=0; i--){
    while(!st.empty() && st.top()>=arr[i])
      st.pop();

    if(st.empty())
      res[i]=-1;
    else 
      res[i]=st.top();

    st.push(arr[i]);
  }
  return res;
}
