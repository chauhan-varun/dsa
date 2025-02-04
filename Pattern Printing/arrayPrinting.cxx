#include<iostream>
using namespace std;
void display(int arr[], int length){
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void change(int arr[], int length){
	arr[0]=23;
}
int main(){
	int arr[]={1,3,4,6,4,3,63};
	int length=sizeof(arr)/sizeof(arr[0]);
	display(arr, length);
	change(arr, length);
	display(arr,length);
}