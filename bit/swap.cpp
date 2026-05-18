#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
  a = a^b;
  b = a^b;
  a = a^b;
}

int main(){
  int  a = 5, b = 7;
  swap(a,b);
  cout<<"a"<<a<<"\n"<<"b"<<b;
}
