#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0; i<a.size(); i++){
		cout<<a.at(i)<<" ";
	}
	cout<<endl;
}
void trap(vector<int> &h){
	int n=h.size();
	vector<int> v(n);
	int max=h[0];
	for(int i=0; i<n; i++){
		v[i]=max;
		if(max<h[i]) max=h[i];
	}
	v[n-1]=-1;
	max=h[n-1];
	for(int i=n-2; i>=0; i--){
		if(max<v[i]) v[i]=max;
	    if(max<h[i]) max=h[i];
	}
	int water=0;
	for(int i=0; i<n; i++){
	    if(v[i]>h[i]) water+=v[i]-h[i];
	}
	cout<<water;
}
int main(){
	vector<int> v;
	
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	
	trap(v);
}