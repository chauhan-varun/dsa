#include<iostream>
#include<vector>
using namespace std;
void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
int main(){
	cout<<"enter the size of matrix : ";
	int n;
	cin>>n;
	int arr[n][n];
	cout<<"enter the matrix : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j) swap(arr[i][j],arr[j][i]);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
}