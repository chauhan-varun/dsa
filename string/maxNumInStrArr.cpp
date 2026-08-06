#include<iostream>
#include<string>
#include<climits>
using namespace std;
int main(){
    string arr[4]={"0423", "4532", "0003","0045"};
    int max=INT_MIN;
    for(int i=0; i<4; i++){
    	if(max<stoi(arr[i])) max=stoi(arr[i]);
    }
    cout<<max;
}