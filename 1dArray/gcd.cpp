#include<iostream>
using namespace std;
int gcd(int x,int y){
	for(int i=min(x,y); i>=1; i-- ){
		if (x%i==0 && y%i==0){
			return i;
			break;
		}
	}
}
int main(){
	int x=19;
	int y=48;
	cout<<gcd(x,y);
}