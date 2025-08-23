#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  int min;
  for (int j = 0; j < n-1; j++) {
    
    min = j;

    for (int i = j + 1; i < n; i++) {
      if (arr[i] < arr[min]) {
        min = i;
      }
    }
    swap(arr[j], arr[min]);
  }


  for(auto x: arr) {
    cout << x << " ";
  }
  return 0;
}
