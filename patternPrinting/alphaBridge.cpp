#include<iostream>
using namespace std;
int main(){
	int n=4,a=65;
	for(int i=1; i<=(2*n-1); i++){
		cout<<(char)a;
		a++;
	}
	cout<<endl;
	for(int i=1; i<=n-1; i++){
		int a=65;
		for(int j=1; j<=n-i; j++){
			cout<<(char)a; 
			a++;
		}
		for(int j=1; j<=(2*i-1); j++){
			cout<<"  ";
			a++;
		}
		for(int j=1; j<=n-i; j++){
			cout<<(char)a;
			a++;
		}
		cout<<endl;
	}
}