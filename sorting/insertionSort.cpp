#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
  // bool swapped;
  int j;
  for(int i=0; i<n; i++){
    
    j=i;
    while(j>0 && arr[j-1]>arr[j]){
      swap(arr[j-1], arr[j]);
      j--;
    }
    // for(int j=0; j<=i; j++){
    //   if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
    // }
  }
}
void printArray(int arr[],int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  printArray(arr, n);
  return 0;
}
