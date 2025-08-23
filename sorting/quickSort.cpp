#include<bits/stdc++.h>
using namespace std;
int getPivotAndSort(vector<int> &arr, int start, int end){
  int pivot = arr[start];
  int i=start;
  int j=end;
  while(i<j){
    while(arr[i]<=pivot && i<end){
      i++;
    }
    while(arr[j]>pivot && j>start){
      j--;
    }
    if(i<j) swap(arr[i], arr[j]);
  }
  swap(arr[start], arr[j]);
  return j;
}
void quickSort(vector<int> &arr, int start, int end){
  if(start<end){
    int pivot = getPivotAndSort(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
  }
}
int main() {
  vector<int> v;
  int n;
  cout<<"Enter the size of Array\n";
  cin>>n;
  cout<<"Enter the elements of Array\n";
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    v.push_back(x);
  }

  quickSort(v, 0, n-1);
  for(auto x: v){
    cout<<x<<" ";
  }
}
