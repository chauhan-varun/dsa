#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {3, 4, 1, 3, 5, 2, 5, 7, 3};
  int n = sizeof(arr) / sizeof(arr[0]); // 9

  bool swapped;
  for(int i=n-1; i>0; i--){
    
    swapped = false;
    for(int j=0; j<i; j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped == false) break;
  }

  for (auto x : arr) {
    cout << x << " ";
  }
  return 0;
}
