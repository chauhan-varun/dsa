#include<bits/stdc++.h>
using namespace std; 

void merge(vector<int> &arr, int start, int mid, int end){
  // start - mid
  // mid +1 - end
  int left = start;
  int right = mid+1;
  vector<int> temp;
  while(left<=mid && right<=end){
    if(arr[left]<=arr[right]){
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while(left<=mid){
    temp.push_back(arr[left]);
    left++;
  }

  while(right<=end){
    temp.push_back(arr[right]);
    right++;
  }

  for(int i=start; i<=end; i++){
    arr[i] = temp[i-start];
  }
}

void mergeSort(vector<int> &arr, int start, int end){
  if(start>=end) return;
  int mid = (start + end) / 2;
  mergeSort(arr,start, mid);
  mergeSort(arr, mid+1, end);
  merge(arr, start, mid, end);
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

  mergeSort(v, 0, n-1);
  for(auto x: v){
    cout<<x<<" ";
  }
}
