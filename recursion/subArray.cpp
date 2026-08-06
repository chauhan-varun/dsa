#include<iostream>
#include<vector>
using namespace std;
void subArr(int arr[], int n, int idx, vector<int> v){
	if(idx==n){
		for(int i=0; i<v.size(); i++) cout<<v[i];
		cout<<endl;
		return;
	}
	subArr(arr, n, idx+1, v);
	if(v.size()==0 || v[v.size()-1]==arr[idx-1]){
		v.push_back(arr[idx]);
		subArr(arr, n, idx+1, v);
	};
}
int main(){
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	vector<int> v;
	subArr(arr, n, 0, v);
}