#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a;
	for(int i=1 ; i<=n ; i++){
		int a=65;
		for (int j=1; j<=i; j++){
			cout<<(char)a;
		a++;
		}
		cout<<endl;
	}
	return 0;
}