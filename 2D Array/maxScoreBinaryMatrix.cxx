#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<int>> &v){
	int m=v.size();
	int n=v[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<v[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void max(vector<vector<int >> &v){
	int m=v.size();
	int n=v[0].size();
	for(int i=0; i<m; i++){
		if(v[i][0]==0){
			for(int j=0; j<n; j++){
				if(v[i][j]==0) v[i][j]=1;
				else v[i][j]=0;
			}
		}
	}
	for(int j=0; j<n; j++){
		int noz=0, noo=0;
		for(int i=0; i<m; i++){
			if(v[i][j]==0) noz++;
			else noo++;
		}
		if(noz>noo){
			for(int i=0; i<m; i++){
				if(v[i][j]==0) v[i][j]=1;
				else v[i][j]=0;
			}
		}
	}
	display(v);
}
int main(){
    int m=3, n=4;
    vector<vector<int >> v;
    for(int i=0; i<m; i++){
    	vector<int> a(n);
    	v.push_back(a);
    }
    for(int i=0; i<m; i++){
    	for(int j=0; j<n; j++){
    		cin>>v[i][j];
    	}
    }
    max(v);
}