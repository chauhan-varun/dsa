#include<iostream>
using namespace std;
int fact(int x){
	int f=1;
	for (int i=1; i<=x; i++)
		f*=i;
		return f;
}
int combination(int n, int r){
	int ncr=fact(n)/(fact(r)*fact(n-r));
	return ncr;
}
int permutation(int n, int r){
	int npr=fact(n)/fact(r);
	return npr;
}
int main(){
	cout<<combination(5,2);
	
}