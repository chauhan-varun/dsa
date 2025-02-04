#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s="foo";
    string t="bar";
    int n=s.size();
    vector<int> v(150,1000);
    int flag=true;
    if(n!=t.size()) flag=false;
    for(int i=0; i<n; i++){
    	int idx=(int)s[i];
    	if(v[idx]==1000) v[idx]=s[i]-t[i];
    	else if(v[idx]!=(s[i]-t[i])) flag=false;
    }
    for(int i=0; i<n; i++){
    	int idx=(int)t[i];
    	if(v[idx]==1000) v[idx]=t[i]-s[i];
    	else if(v[idx]!=(t[i]-s[i])) flag=false;
    }
    cout<<flag;
}