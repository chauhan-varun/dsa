#include <bits/stdc++.h>
using namespace std;

class DynamicArr {
  private:
  int *arr; 
  int cap;
  int size;
  
  public:
  DynamicArr(int cap){
    this->cap = cap;
    arr = new int[cap];
    size = 0;
  }

  void resize(){
    cap*= 2;
    int* newArr = new int[cap];
    for(int i = 0; i<size; i++){
      newArr[i] = arr[i];
    }
    delete [] arr;
    arr = newArr;
  }

  void push_back(int x){
    if(size == cap) resize();
    
    arr[size++] = x;
  }

  ~DynamicArr(){
    delete [] arr;
  }
};
