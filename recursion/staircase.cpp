#include<iostream>
using namespace std;
int ways(int n){
	if(n==0 || n==1) return 1;
	if(n==2 ) return 2;
	return ways(n-1) + ways(n-2) + ways(n-3);
}
int main(){
	int n=4;
	cout<<ways(n);
}