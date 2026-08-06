 #include<iostream>
 using namespace std;
 int main(){
 	int n;
 	cout<<"Enter number of elements: ";
 	cin>>n;
 	int arr[n];
 	for(int i=0; i<=n-1; i++){
 		cin>>arr[i];
 	}
 	cout<<"enter the element x"; //count the number of element greater than x
 	int x;
 	cin>>x;
 	int num=0;
 	for(int i=0; i<=n-1; i++){
 		if(x<arr[i]) num++; 
 	}
 	cout<<num;
 }