#include<iostream>
#include<climits>
using namespace std;
int maxx(int arr[], int n, int idx, int mx){
	if(idx==n) return INT_MIN;
	return max(arr[idx], maxx(arr, n, idx+1, mx));
}
int main(){
    int arr[]={2,3,4,6,7,8,9,13,52,53,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxx(arr, n, 0, INT_MIN);
}