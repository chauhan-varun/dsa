#include<iostream>
using namespace std;
int main(){
	int n=4,a=1;
	for(int i=1; i<=(2*n-1); i++){
		cout<<a;
		if(i<n) a++;
		else a--;
	}
	cout<<endl;
	for(int i=1; i<=n-1; i++){
		int a=0;
		for(int j=1; j<=n-i; j++){
			a++;
			cout<<a; 
		}
		for(int j=1; j<=(2*i-1); j++){
			cout<<"  ";
		}
		for(int j=1; j<=n-i; j++){
			cout<<a;
			a--;
		}
		cout<<endl;
	}
}