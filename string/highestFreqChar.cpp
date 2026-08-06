#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	string s= "leetcode";
	vector<int> v(26, 0);
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		int ascii=(int)c;
		v[ascii-97]++;
	}
	int max=INT_MIN;
	for(int i=0; i<26; i++){
		if(v[i]>max) max=v[i]; 
	}
	for(int i=0; i<26; i++){
		if(v[i]==max) cout<<(char)(i+97)<<" "<<max;
	}
}