#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={3,7,2,4,9,0,5,6};
    int n=8; 
    for(int i=0; i<n; i++){
    	int min=INT_MAX, idx;
    	for(int j=i; j<n; j++){
    		if(arr[j]<min){
    			min=arr[j];
    			idx=j;
    		}
    	}
    	swap(arr[idx], arr[i]);
    }
    for(int ele : arr) cout<<ele;
}