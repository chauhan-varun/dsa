#include<iostream>
using namespace std;
int main(){
	int n=4;
	for(int i=1; i<=n; i++){
		int a=64+n;
		for(int j=1; j<=n-i; j++){
			cout<<"  ";
			a--;
		}
		for(int j=1; j<=i; j++){
			cout<<(char)a;
			a--;
		}
		int b=66;
		for(int j=1; j<=i-1; j++){
			cout<<(char)b;
			b++;
		}
		cout<<endl;
	}
}