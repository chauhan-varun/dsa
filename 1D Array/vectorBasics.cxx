#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0; i<a.size(); i++){
		cout<<a.at(i)<<" ";
	}
	cout<<endl;
}
int main(){
	vector<int> v;
	for(int i=0; i<=5; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	display(v);
	cout<<endl;
	cout<<v.size()<<" "<<v.capacity()<<endl;
	sort(v.begin(),v.end());
	display(v);
}