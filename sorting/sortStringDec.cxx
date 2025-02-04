#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="azyzxbdjkx";
    string t;
    for(int i=0; i<s.size(); i++){
    	if(s[i]<'x') t.push_back(s[i]);
    }
    int n=t.size();
    for(int i=0; i<n-1; i++){
    	bool flag=true;
    	for(int j=0; j<n-1-i; j++){
    		if(t[i]>t[i+1]){
    			swap(t[i], t[i+1]);
    			flag=false; 
    		}  
    	}
    	if(flag==true) break;
    }
    reverse(t.begin(),t.end());
    cout<<t;
}