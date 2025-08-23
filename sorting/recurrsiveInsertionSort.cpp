#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr, int i) {
  if(i>=arr.size()) return;
  int j=i;
  while(j>0 && arr[j-1]>arr[j]){
    swap(arr[j],arr[j-1]);
      j--;
  }
  insertionSort(arr, i+1);
}
int main() {
  vector<int> arr = {3,2,1,5,7,3,4,5};
  insertionSort(arr, 1);
  for (auto x : arr) {
    cout << x << " ";
  }
  return 0;
}
