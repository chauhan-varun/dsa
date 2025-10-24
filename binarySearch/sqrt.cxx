#include<iostream>
using namespace std;
int main(){
    int x=1000;
    int lo=0, hi=x;
    bool flag=false;
    while(lo<=hi){
    		int mid = lo + (hi-lo)/2;
    		long long m=(long long)mid;
    		long long y= (long long)x;
    		if((m* m)==y){
    			cout<<(m* m);
    			flag=true;
    			break;
    		}
    		else if((m* m)>y) hi=mid-1;
    		else lo=mid+1;
    }
    if(flag==0)
    cout<<(hi);
}