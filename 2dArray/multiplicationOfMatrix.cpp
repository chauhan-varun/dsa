#include<iostream>
using namespace std;
int main(){
	int m,n,p,q;
	cout<<"enter number of rows of matrix 1: ";
	cin>>m;
	cout<<"enter number of columns of matrix 1: ";
	cin>>n;
	cout<<"enter number of rows of matrix 2: ";
	cin>>p;
	cout<<"enter number of columns of matrix 2: ";
	cin>>q;
	cout<<"enter elements of matrix 1: "<<endl;
	int arr[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	
	int brr[p][q];
	cout<<"enter elements of matrix 2: "<<endl; 
	for(int i=0; i<p; i++){
		for(int j=0; j<q; j++){
			cin>>brr[i][j];
		}
	}
	
	int res[m][q];
	for(int i=0; i<m; i++){
		for(int j=0; j<q; j++){
			res[i][j]=0;
			for(int k=0; k<n; k++){
				res[i][j]+=arr[i][k]*brr[k][j];
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<q; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}