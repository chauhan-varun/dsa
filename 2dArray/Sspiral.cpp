#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    int n=3;
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
    for(int i=0; i<n;){
    	
    	for(int j=0; j<n; j++){
    		cout<<arr[i][j]<<" ";
    	}
    	i++;
    	if(i>=n) break; 
    	for(int j=n-1; j>=0; j--){
    		cout<<arr[i][j]<<" ";
    	}
    	i++;
    }
}