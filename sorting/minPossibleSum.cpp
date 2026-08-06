#include <iostream>
using namespace std;
int main(){
	int arr[] ={9,5,4,9,8,6,1,5};
	int n=8;
	for(int i=0; i<n; i++){
		int min=INT_MAX;
		int idx;
		for(int j=i; j<n; j++){
			if(min>arr[j]){
				min=arr[j];
				idx=j;
			}
		}
		swap(arr[i],arr[idx]);
	}
	int product=1, sum=0;
	for(int i=n-1; i>=0; i--){
		sum+=arr[i]*product;
		product*=10;
	}
	for(int i=n-1; i>0; i--){
		if(arr[i]!=arr[i-1]){
			swap(arr[i],arr[i-1]);
			break;
		}
	}
	product=1;
	int sum1=0;
	for(int i=n-1; i>=0; i--){
		sum1+=arr[i]*product;
		product*=10;
	}
	cout<<sum1+sum;
}