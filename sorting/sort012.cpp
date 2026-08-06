#include<iostream>
#include<vector>
using namespace std;
void sort2(vector<int>& v){
	int no0=0,no1=0,no2=0;
	for(int i=0; i<v.size(); i++){
		if (v[i]==0) no0++;
		else if(v[i]==1) no1++;
		else no2++;
	}
	for(int i=0; i<=v.size()-1; i++){
		if (i<no0) v[i]=0;
		else if(i<(no1+no0)) v[i]=1;
		else v[i]=2;
	}
	return;
}
void display(vector<int> &v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
}
int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(0);
	sort2(v);
	display(v);
}