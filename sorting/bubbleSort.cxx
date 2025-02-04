#include<iostream>
using namespace std;
int main(){
    int arr[]={2,6,8,4,3,5,7,9};
    int n=8;
    for(int i=0; i<n-1; i++){
    	bool flag=1;
    	for(int j=0; j<n-1-i; j++){
    		if(arr[j]>arr[j+1]){
    			swap(arr[j], arr[j+1]);
    			flag=0;
    		}
    	}
    	if(flag==1) break;
    }
    for(int i=0; i<n; i++){
    	cout<<arr[i];
    }
}