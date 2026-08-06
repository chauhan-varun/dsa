#include<iostream>
using namespace std;
int main(){
	int n=4;
	for(int i=1; i<=n; i++){
		int a=65;
		for(int j=1; j<=n-i; j++){
			cout<<"  ";
		}
		for(int j=1; j<=(2*i-1); j++){
			cout<<(char)a;
			a++;
		}
		cout<<endl;
	}
}