#include<iostream>
using namespace std;
void print(int arr[], int n){
	if(n==-1) return;
	print(arr, n-1);
	cout<<arr[n-1]<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=6;
   print(arr, n);
}