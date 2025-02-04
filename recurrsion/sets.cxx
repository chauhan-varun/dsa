#include<iostream>
#include<string>
using namespace std;
void sets(string originalString, string newString, bool flag){
	if(originalString==""){
		cout<<newString<<endl;
		return;
	}
	if(originalString.size()==1 || originalString[0]!=originalString[1]){
		if(flag==true) sets(originalString.substr(1), newString+originalString[0],true);
		sets(originalString.substr(1),newString, true);
	}
	else{
		if(flag==true) sets(originalString.substr(1), newString+originalString[0],true);
		sets(originalString.substr(1),newString, false);
	}
}
int main(){
	string s="aab";
	sets(s, "", true);
}