#include<iostream>
#include<string>
using namespace std;
void per(string n, string o){
	if(o==""){
		cout<<n<<endl;
		return;
	}
	for(int i=0; i<o.size(); i++){
		char m=o[i];
		string f=o.substr(0, i);
		string l=o.substr(i+1);
		per(n+m, f+l);
	}
}
int main(){
	string s="abc";
	per("",s);
}