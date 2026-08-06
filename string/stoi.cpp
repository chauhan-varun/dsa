#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0, product =1;
    for(int i=n-1; i>=0; i--){
    	ans+=(s[i]-'0')*product;
    	product *=10;
    }
    cout<<ans;
}