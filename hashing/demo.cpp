#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cout<<"enter the size of array"<<endl;
    cin>>n;
    cout<<"enter the elements of array"<<endl;
    int arr[n];
    for(int &i: arr){
        cin>>i;
    }
    
    map<int, int> mpp;
    
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    
        
    int min = INT_MAX;
    int max = INT_MIN;
    for(auto i: mpp){
        if(i.second < min){
            min = i.second;
        }
        if(i.second > max){
            max = i.second;
        }
    }
    
    cout<<"the minimum frequency is "<<min<< endl<<"the maximum frequency is "<<max<<endl;
    return 0;
}
