#include<iostream>
using namespace std;
int main(){
    int arr[]={1,3,5,4,3,2,1};
    int n=7, idx=-1;
    int lo=1, hi=n-2;
    while(lo<=hi){
    	int mid=lo+(hi-lo)/2;
    	if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
    		idx=mid;
    		break;
    	} 
    	else if(arr[mid]<arr[mid+1]) lo=mid+1;
    	else hi=mid-1;
    }
    cout<<idx; 
}