#include<iostream>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<string> v;
    v.push_back("flow");
    v.push_back("flower");
    v.push_back("flight");
    sort(v.begin(),v.end());
    int n= v.size();
    string first = v[0];
    string last = v[n-1];
    string com="";
    for(int i=0; i<min(first.size(),last.size()); i++){
    	if(first[i]==last[i]) com+=first[i];
    }
    cout<<com;
}