#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  int n;
  cout<<"Enter the size"<<endl;
  cin>>n;
  vector<int> arr(n);
  for(int e: arr) cin>>e;

  int x = arr[n-1];

  bool found = false;
  auto start = high_resolution_clock::now();
  for(int e: arr){
    if(x == e) {
      found = true;
      break;
    }
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  auto space = sizeof(arr) + (n * sizeof(int)) + sizeof(found) + sizeof(x);
  cout<< duration.count();
}
