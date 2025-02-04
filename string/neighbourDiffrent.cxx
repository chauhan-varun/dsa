#include<iostream>
#include<string>
using namespace std;
int main(){
	string str= "abbccdvddgeegefds";
	int count=0, n=str.length();
	for(int i=1; i<n-1; i++){
	     if(str[i]==str[i+1]) count++;
      } 
      cout<<count;
}