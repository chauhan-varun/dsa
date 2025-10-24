#include<iostream>
using namespace std;
int main(){
    int arr[]={0,1,2,3,4,5,6,7,8,22, 44};
    int n=10, lo=0,hi=n-1, ans=-1;
    while(lo<=hi){
    	int mid=lo+(hi-lo)/2;
    	if(arr[mid]==mid) lo=mid+1;
    	else{
    		ans=mid;
    		hi=mid-1;
    	}
    }
    cout<<ans;
}