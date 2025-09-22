#include<bits/stdc++.h>
using namespace std;

//better
int longestConsecutive(vector<int>& arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int longest = 1, lastSmaller = INT_MIN, count = 0;

  for(int i = 0; i<n; i++){
    if(arr[i] - 1 ==lastSmaller){
      count++;
      lastSmaller = arr[i];
    } else if(arr[i] != lastSmaller) {
      lastSmaller = arr[i];
      count = 1;
    }
    longest = max(count, longest);
  }
  return longest;
}

int main() {
  vector<int> arr = {100, 4, 200, 1, 3, 2};
  cout<<longestConsecutive(arr);
	return 0;
}
