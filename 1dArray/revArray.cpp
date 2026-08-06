#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0; i<a.size(); i++){
		cout<<a.at(i)<<" ";
	}
}
void reverse(vector<int> &v){
	for(int i=0, j=v.size()-1; i<=j; i++, j--){
		int temp=v[i];
		v[i]=v[j];
		v[j]=temp;
	}
	cout<<endl;
	return;
}
void reversePart(int i, int j, vector<int> &v){
	while(i<=j){
		int temp=v[i];
		v[i]=v[j];
		v[j]=temp;
		i++;
		j--;
	}
	cout<<endl;
	return;
}
int main(){
	vector<int> v;
	cout<<"enter the size of array: ";
	int n; 
	cin>>n;
	cout<<"enter the array: "<<endl;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	//reverse(v);
	display(v);
	cout<<" enter the part you want to reverse: ";
	int x,y;
	cin>>x>>y;
	reversePart(x,y,v);
	display(v);
}