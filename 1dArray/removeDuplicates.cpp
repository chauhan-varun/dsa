#include <bits/stdc++.h>
using namespace std;
void removeDuplicates(vector<int> &arr) {
  int n = arr.size();
  int j = 1;
  for(int i=0; i<n; i++){
    if(arr[i] != arr[j-1]){
      swap(arr[j], arr[i]);
      j++;
    }
  }
}
int main() {
  vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  removeDuplicates(arr);
  for (auto i : arr)
    cout << i << " ";
}
