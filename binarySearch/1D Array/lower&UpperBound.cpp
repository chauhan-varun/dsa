#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int x) {
    int n = arr.size(), i = 0, j = n - 1, ans = n;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (arr[mid] >= x) { // first >= x
            ans = mid;
            j = mid - 1;
        } else i = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> &arr, int x) {
    int n = arr.size(), i = 0, j = n - 1, ans = n;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (arr[mid] > x) { // first > x
            ans = mid;
            j = mid - 1;
        } else i = mid + 1;
    }
    return ans;
}
int main() {
  vector<int> arr = {1,2,3,4,5,6,6,8,9};
                   //0,1,2,3,4,5,6,7,8
  cout<<lowerBound(arr, 7);
}
