#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sort(vector<int> &arr, int i, int high, bool &flag){
  
  if(i>=high) return;
  if(arr[i]>arr[i+1]) {
    swap(arr[i], arr[i+1]);
    flag = true;
  }
  sort(arr, i+1, high, flag);
}
vector<int> bubbleSort(vector<int> &arr,  int n, bool &flag) {
  if (n<0 || flag)
    return arr;
  
  sort(arr,0, n, flag);
  bubbleSort(arr, n - 1, flag);
  return arr;
}

int main() {
  vector<int> arr = {7, 3, 1, 5, 2, 6};

  vector<int> v = bubbleSort(arr, arr.size() - 1, false);
  for (auto x : v) {
    cout << x << " ";
  }
}
