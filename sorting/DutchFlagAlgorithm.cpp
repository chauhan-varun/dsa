#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0; i<=5; i++){
		cout<<a.at(i)<<" ";
	}
}
void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
void sort1(vector<int> &v){
	int mid=0, lo=0, hi=v.size()-1;
	while(mid<=hi){
		if(v[mid]==2){
			swap(v[mid],v[hi]);
			hi--;
		}
		else if(v[mid]==0){
			swap(v[mid],v[lo]);
			mid++; lo++;
		}
		else{
			mid++;
		}
	}
	return;
}
int main(){
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	sort1(v);
	display(v);
	
}