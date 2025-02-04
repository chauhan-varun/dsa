#include<iostream>
#include<string>
using namespace std;
int main(){
    string arr[] = {"physicswallah","quiz","practice", "pwskills","coding" };
    int n=5;
    for(int i=0; i<n-1; i++){
    	bool flag=true;
    	for(int j=0; j<n-1-i; j++){
    		if(arr[j]>arr[j+1]){
    			flag=false;
    			swap(arr[j], arr[j+1]);
    		}
    	}
    	if(flag==1) break; 
    } 
    for(string ele : arr) cout<<ele<<" ";
    
}