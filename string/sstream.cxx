#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string str="mansi is a wrost teacher";
    //getline(cin,s)--> for input
    stringstream ss(str);
    string temp;
    while(ss>>temp){
    	cout<<temp<<endl;
    }
}