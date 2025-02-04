#include<iostream>
using namespace std;
int main(){
	int arr[]={1,2,3,4,2,45,5,764,67,4,4,435,7,4,353,25};
	int n=(sizeof(arr)/4);
	int max=arr[0];
	for(int i=1; i<=n-1; i++){
		if (max<arr[i]) max=arr[i];
	}  //largest element
	int max2=arr[0];
	for(int i=1; i<=n-1; i++){
			if (arr[i]==max){
				continue;
			}
			else if(max2<arr[i]) max2=arr[i];
	} //secont largest element
	cout<<max<<" "<<max2;
	
}