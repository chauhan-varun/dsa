#include<iostream>
using namespace std;
int main(){
    int arr[]={3,7,2,4,9,4,6,5};
    int n=8;
    for(int i=0; i<n; i++){
    	int j=i;
    	while(j>=1 && arr[j]<arr[j-1]){
    		swap(arr[j], arr[j-1]);
    		j--;
    	}
    }
    for(int ele : arr) cout<<ele;
}