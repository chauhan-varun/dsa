#include<iostream>
#include<climits>
using namespace std;
int main(){
	int arr[3][3]={2,3,1,7,7,4,8,9,3};
	int brr[3][3]={1,2,4,7,9,0,4,3,3};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			arr[i][j]=brr[i][j]+arr[i][j];
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<arr[i][j]<<" ";
		}
	}
	cout<<endl;
	
}