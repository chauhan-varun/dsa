#include<iostream>
using namespace std;
int main(){
	int arr[7]={1,3,4,7,1,4,3};
	for(int i=0; i<7; i++){
		int j;
		for(j=0; j<7; j++){
			 if(arr[i]==arr[j] && i!=j) break;
		}
		if(j==7){
		cout<<arr[i];
		break;
		}
	}
}