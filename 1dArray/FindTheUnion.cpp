#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
vector<int> unionn(vector<int> &arr1, vector<int> &arr2) {
  vector<int> arr;
  int n = (arr2.size()+ arr1.size());
  int j = 0, i = 0;
  while(i<arr1.size() && j<arr2.size()){
    if (arr1[i] < arr2[j]) {
      arr.push_back(arr1[i]);
      i++;
    } else if (arr1[i] > arr2[j]) {
      arr.push_back(arr2[j]);
      j++;
    } else {
      arr.push_back(arr1[i]);
      i++;
      j++;
    }
  }

  while(i<arr1.size()){
    arr.push_back(arr1[i]);
    i++;
  }
  
  while(j<arr2.size()){
    arr.push_back(arr2[j]);
    j++;
  }
  
  return arr;
}
int main() {
  vector<int> arr1 = {1, 2, 3, 4, 7};
  vector<int> arr2 = {2, 3, 4, 5};
  vector<int> arr = unionn(arr1, arr2);
  for (auto x : arr) {
    cout << x << " ";
  }
}
