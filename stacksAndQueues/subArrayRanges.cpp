#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> nse(vector<int> &arr) {
  int n = arr.size();
  vector<int> res(n);

  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i])
      st.pop();
    res[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return res;
}

vector<int> ngee(vector<int> &arr) {
  int n = arr.size();
  vector<int> res(n);

  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] < arr[i])
      st.pop();
    res[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return res;
}
vector<int> psee(vector<int> &arr) {
  int n = arr.size();
  vector<int> res(n);

  stack<int> st;
  for (int i =0; i<n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i])
      st.pop();
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return res;
}
vector<int> pge(vector<int> &arr) {
  int n = arr.size();
  vector<int> res(n);

  stack<int> st;
  for (int i=0; i<n; i++) {
    while (!st.empty() && arr[st.top()] <= arr[i])
      st.pop();
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return res;
}

long long sumSubArrMin(vector<int>&arr){
  long long ans =0;
  vector<int> ps= psee(arr);
  vector<int> ns=nse(arr);
  int n = arr.size();
  for(int i=0;i<n;i++){
    long long left = i-ps[i];
    long long right = ns[i]-i;
    ans = (ans + left * right * arr[i]);
  }
  return ans;
}


long long sumSubArrMax(vector<int>&arr){
  long long ans =0;
  vector<int> pg= pge(arr);
  vector<int> ng=ngee(arr);
  int n = arr.size();
  for(int i=0;i<n;i++){
    long long left = i-pg[i];
    long long right = ng[i]-i;
    ans = (ans + left * right * arr[i]);
  }
  return ans;
}
long long subArrayRanges(vector<int> &arr) {
  return sumSubArrMax(arr) - sumSubArrMin(arr);
}
