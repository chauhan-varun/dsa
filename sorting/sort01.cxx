#include<iostream>
#include<vector>
using namespace std;
void sort1(vector<int> &v){
	int noz=0,noo=0;
	for(int i=0; i<v.size(); i++){
		if(v[i]==0) noz++;
		else noo++;
	}
	for(int i=0; i<v.size(); i++){
		if(i<noz) v[i]=0;
		else v[i]=1;
	}
	return;
}
void sort2(vector<int>& v){
	int i=0,j=v.size()-1;
	while(i<j){
		if(v[i]==0) i++;
		if(v[j]==1) j--;
		else if(v[i]==1 && v[j]==0){
			v[i]=0; v[j]=1;
			i++; j--;
		}
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
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	sort2(v);
	display(v);
}