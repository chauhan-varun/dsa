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
 	cout<<"enter the element you want to search";
 	int x;
 	cin>>x;
 	bool flag=false;
 	for(int i=0; i<=n-1; i++){
 		if (arr[i]==x) flag=true;
 	}
 	if(flag==true) cout<<"present";
 	else cout<<"not present";
 	
 }