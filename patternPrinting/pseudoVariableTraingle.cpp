#include<iostream>
using namespace std;
int main(){
	int n=4;
	for(int i=1; i<=n; i++){
		int a=n;
		for(int j=1; j<=n-i; j++){
			cout<<"  ";
			a--;
		}
		for(int j=1; j<=i; j++){
			cout<<a;
			a--;
		}
		cout<<endl;
	}
}