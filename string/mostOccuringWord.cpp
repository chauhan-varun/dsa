#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string temp;
    vector<string> v;
    while(ss>>temp){
    	v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int maxc=0;
    int count=1;
    for(int i=0; i<v.size()-1; i++){
    	if(v[i]==v[i+1]) count++;
    	else count=1;
    	maxc=max(maxc,count); 
    }
     count=1;
    for(int i=0; i<v.size()-1; i++){
    	if(v[i]==v[i+1]) count++;
    	else count=1;
    	if(maxc==count) cout<<v[i]<<maxc; 
    }
    
}