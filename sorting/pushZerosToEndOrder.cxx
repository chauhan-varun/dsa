#include<iostream>
using namespace std;
int main(){
    int arr[]={2,0,8,4,0,5,7,0};
    int n=8;
    for(int i=0; i<n-1; i++){
    	bool flag=1;
    	for(int j=0; j<n-1-i; j++){
    		if(arr[j]==0){
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