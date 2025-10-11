#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
void insertAtIndex(int arr[], int &len, int cap, int p, int val) {
  // Preconditions: 0 ≤ p ≤ len ≤ cap
  if (p < 0 || p > len || len >= cap) {
    cerr << "Invalid position or array full."; 
    return;
  }
  for (int i = len; i > p; --i) {
    arr[i] = arr[i - 1];
  }
  arr[p] = val;
  len++; // Update length
}

int deleteFirst(int arr[], int v, int &n){
  for(int i = 0; i<n; i++){
    if(arr[i] == v){
      int idx = i;
      while(i<n-1){
        arr[i] = arr[i+1];
        i++;
      }
      n--;
      return idx;
    }
  }
  cout<<"not fount";
  return -1;
}

void print(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

vector<int> duplicate(vector<int> &arr){
  set<int> st;
  set<int> dup;
  int n = arr.size();
  for(int i = 0; i<n; i++){
    if(st.find(arr[i]) != st.end()) dup.insert(arr[i]);
    st.insert(arr[i]);
  }
  return vector<int> (dup.begin(), dup.end());
}

int main() {
  // int arr[] = {0, 1, 2, 3, 4};
  // int n = 5;
  // deleteFirst(arr, 3, n);
  // print(arr, n);
  vector<int> arr  = {1,2,4,4,6,7,3,2,23,4};
  vector<int> dup = duplicate(arr);
  for(auto e: dup) cout<< e <<" ";
}
