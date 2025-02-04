#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<int >> &v, int &x){
	int n=v.size(), i=0, j=n-1;
	while(i<n && j>=0){
		if(v[i][j]==x) return true;
		else if(v[i][j]>x) j--;
		else i++;
	}
	return false;
}
int main(){
    int n=5;
    vector<vector<int >> v;
    for(int i=0; i<n; i++){
    	vector<int> a(n);
    	v.push_back(a);
    }
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin>>v[i][j];
    	}
    }
    cout<<"enter target : ";
    int x;
    cin>>x;
    bool flag=search(v,x);
    if(flag==true) cout<<"true";
    else cout<<"false";
}