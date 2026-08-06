#include<iostream>
using namespace std;
int main(){
	int arr[5]={1,3,4,6,3};
	int* ptr=arr;
	for(int i=0; i<=4; i++){
		cout<<*ptr<<" ";
		ptr++;
	}
}