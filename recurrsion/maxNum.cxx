#include<iostream>
using namespace std;
void max(int arr[], int n, int &mx){
	if(n==-1) return;
	if(mx<arr[n-1]) mx=arr[n-1];
	return max(arr,n-1, mx);
}
int main(){
    int arr[]={1,2,7,4,5,6};
    int n=6, idx=-1;
   max(arr, n, idx);
   cout<<idx;
}