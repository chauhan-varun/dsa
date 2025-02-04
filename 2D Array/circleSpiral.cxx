#include<iostream>
using namespace std;
int main(){
    int n=4;
    int arr[n][n];
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin>>arr[i][j];
    	}
    }
    
    int minr=0, minc=0, maxr=n-1, maxc=n-1, tne=n*n, count=0;
    while(minr<=maxr && minc<=maxc){
    	for(int j=minc; j<=maxc && count<tne; j++){
    		cout<<arr[minr][j];
    		count++;
    	}
    	minr++;
    	for(int i=minr; i<=maxr && count<tne;  i++){
    		cout<<arr[i][maxc];
    		count++;
    	}
    	maxc--;
    	for(int j=maxc; j>=minc && count<tne; j--){
    		cout<<arr[maxr][j];
    		count++;
    	}
    	maxr--;
    	for(int i=maxr; i>=minr && count<tne; i--){
    		cout<<arr[i][minc];
    		count++;
    	}
    	minc++;
    	
    }
}