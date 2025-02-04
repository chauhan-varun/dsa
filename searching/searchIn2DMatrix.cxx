#include<iostream>
using namespace std;
int main(){
	int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int m=4, n=3, x=10;
	int lo=0, hi=m*n-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid/m][mid%m]==x){
			cout<<mid/m<<" "<<mid%m; 
			return 0;
		} 
		else if(arr[mid/m][mid%m]>x) hi=mid-1;
		else lo=mid+1;
		
	}
}