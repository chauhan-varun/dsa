#include<iostream>
#include<vector>
using namespace std;
int main(){
	int x;
	cout<<"enter target: ";
	cin>>x;
	cout<<"enter size of array: ";
	int n;
	cin>>n;
	cout<<"enter the array: ";
	vector<int> v;
	for(int i=0; i<n; i++){
		int y;
		cin>>y;
		v.push_back(y);
	}
	for(int i=0; i<v.size()-1; i++){
		for(int j=i+1; j<v.size(); j++){
			if((v[i]+v[j])==x) cout<<i<<" "<<j<<endl;
		}	
	}
}