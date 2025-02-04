#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v;
	cout<<"enter the size of array: ";
	int n;
	cin>>n;
	cout<<"enter the array: ";
	for(int i=0; i<n; i++){
		int y;
		cin>>y;
		v.push_back(y);
	}
	vector<int> v2(v.size());
	for(int i=0; i<n; i++){
		v2[i]=v[v.size()-1-i];
	}
	for(int i=0; i<n; i++){
		cout<<v2.at(i)<<" ";
	}
}