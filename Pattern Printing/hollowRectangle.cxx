#include<iostream>
using namespace std;
int main(){
	int m=4,n=6;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if (i==1 || j==1 || j==n || i==m) cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
	}
}