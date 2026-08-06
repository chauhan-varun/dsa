#include<iostream>
using namespace std;
int main(){
	int curr;
	int n=5;
	for(int i=0; i<=n; i++){
		curr=1;
		for(int j=0; j<=i; j++){
			cout<<curr;
			curr=curr*(i-j)/(j+1);
		}
		cout<<endl;
	}
}