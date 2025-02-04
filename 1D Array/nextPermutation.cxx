#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0; i<a.size(); i++){
		cout<<a.at(i)<<" ";
	}
	cout<<endl;
}
void nextPermutation(vector<int> &v){
	int idx=-1;
	int n=v.size();
	for(int i=n-2; i>=0; i--){
		if(v[i]<v[i+1]){
			idx=i;
			break;
		}
	}
	if(idx==-1){
		reverse(v.begin(),v.end());
	}
	reverse(v.begin()+idx+1,v.end());
	int j=-1;
	for(int i=idx+1; i<n; i++){
		if(v[idx]<v[i]){
			j=i;
			break;
		}
	}
	int temp=v[idx];
	v[idx]=v[j];
	v[j]=temp;
	return;
}
int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	//v.push_back(3);
	nextPermutation(v);
	display(v);
}