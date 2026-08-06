#include<iostream>
using namespace std;
int raise(int a, int b){

	if(b==1) return a;
	int ans=raise(a,b/2);
	if(b%2==0) return ans * ans;
	else return ans * ans *a;
}
int main(){
    int a=2,b=9;
    cout<<raise(a,b);
}