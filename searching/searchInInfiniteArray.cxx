#include<iostream>
using namespace std;
int main(){
	int arr[]={1,2,3,4,5,7,8,9,10};
	int n=9;
	int lo=0, hi=1;
	while(lo<=hi){
		if(arr[hi]<x) hi*=2;
		else if(arr[hi]>x) break;
		else lo+=1;
	}
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==x){
			cout<<mid; 
			return 0;
		} 
		else if(arr[mid]>x) hi=mid-1;
		else lo=mid+1;
		
	}
}