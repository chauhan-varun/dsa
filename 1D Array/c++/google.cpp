#include<iostream>
using namespace std;
int main() {
   
    cout<<"Enter the elements of the array\n";
    int arr[10],sum=0;

    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<"\nsum"<<sum;
}
