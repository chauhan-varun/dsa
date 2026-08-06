#include<iostream>
using namespace std;
int main(){
	int arr[7];
	cout<<"enter array of element 7 : ";
	for(int i=0; i<7; i++){
		cin>>arr[i];
	}
	bool flag;
	for(int i=0; i<6; i++){
		if(arr[i]<arr[i+1]){ 
			flag=true;
			
		}
		else {
			flag=false;
			break;
		}
	}
	if(flag==true) cout<<"sorted";
	else cout<<"not sorted";
	
}