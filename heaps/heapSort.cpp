#include <bits/stdc++.h>
#include <utility>
using namespace std;
class Heap {
public:
  int arr[101];
  int size;
  
  Heap() { size = 0; }
};

void heapify(int a[], int n, int idx){
  
  while(true) {
    int left = idx * 2; 
    int right = left + 1;
    int large = idx;

    if(left <= n && a[large]< a[left]) large = left;
    if(right <= n && a[large]< a[right]) large = right;
     
    if(large != idx) {
      swap(a[large], a[idx]);
      idx = large;
    } else return;
  }
}
void heapSort(int a[], int size) {
  while (size!= 1) {
    swap(a[1], a[size--]);
    heapify(a, size, 1);
  }
}
