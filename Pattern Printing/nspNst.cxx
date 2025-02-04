#include<iostream>
using namespace std;
int main(){
	int n=4,nsp=n-1,nst=1;
	for(int i=1; i<=2*n-1; i++){
		
		for(int j=1; j<=nsp; j++){
			cout<<" ";
		}
		for(int j=1; j<=nst; j++){
			cout<<"*";
		}
		cout<<endl;
		if(i<=3){
			nsp--;
			nst++;
		}
		else {
			nsp++;
			nst--;
		} 
	}
}