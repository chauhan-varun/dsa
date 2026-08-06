#include<bits/stdc++.h>
using namespace std;
int main() {
  int arr[] = {5,2,5,7,2,3, 7};
  int n = 6;
  int max1 = INT_MIN, max2 = INT_MIN;
  int min1 = INT_MAX, min2 = INT_MAX;

  for(int i = 0; i <n ; i++){
    if(arr[i]>max1){
      max2 = max1;
      max1 = arr[i];
    } else if(arr[i]<max1 && arr[i] != max1 && arr[i]>max2){
      max2 = arr[i];
    }
  }

  for(int i = 0; i<n; i++) {
    if(arr[i]<min1){
      min2 = min1;
      min1 = arr[i];
    } else if(arr[i]>min1 && min2>arr[i] && min1 != arr[i]){
      min2 = arr[i];
    }
  }
  
cout<<max2<<" "<< min2;
}
