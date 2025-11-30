#include<iostream>
using namespace std;
int rev(int n){
	static int a=0;
	if(n==0) return a;
	a=a*10+(n%10);
	return rev(n/10);
}
int main(){
	int n=4524;
	cout<<rev(n);
}