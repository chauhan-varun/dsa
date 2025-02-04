#include<iostream>
using namespace std;
int fab(int n){
	if (n==1) return 0;
	if (n==2) return 1;
	return fab(n-1)+ fab(n-2);
}
int main(){
    cout<<fab(7);
}