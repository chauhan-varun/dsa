#include<iostream>
using namespace std;
int main(){
    int n=3;
    int arr[n][n];
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin>>arr[i][j];
    	}
    }
    int noe=n*n;
    int count=0;
    for(int j=0; j<n; j++){
    	for(int i=n-1; i>=0 && count<noe; i--){
    		cout<<arr[i][j]<<" ";
    		count++;
    	}
    	j++;
    	for(int i=0; i<n && count<noe; i++){
    		cout<<arr[i][j]<<" ";
    		count++;
    	}
    }
}