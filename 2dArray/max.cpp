#include<iostream>
#include<climits>
using namespace std;
int main(){
	int arr[3][3]={2,3,1,7,57,4,8,9,3};
	int max=INT_MIN;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(max<arr[i][j]) max=arr[i][j];
		}
	}
	cout<<max;
}