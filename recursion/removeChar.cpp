#include<iostream>
#include<string>
using namespace std;
void rchar(string a, string o, int idx){
	if(idx==o.size()){
		cout<<a;
		return;
	}
	if(o[idx]=='a') return rchar(a , o,  idx+1);
	else return rchar(a+o[idx] , o ,  idx+1);
}
int main(){
    string s="varun chauhan";
    rchar("", s, 0);
}