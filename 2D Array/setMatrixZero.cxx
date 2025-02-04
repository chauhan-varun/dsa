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
void rcZero(vector<vector<int >> &v){
	int m=v.size();
	int n=v[0].size();
	int flag=0;
	for(int i=0; i<m; i++){
		if (v[i][0]==0) flag=1;
		for(int j=0; j<n; j++){
			if(v[i][j]==0){
				v[i][0]=v[0][i]=0;			
			}
		}
	}
	display(v);
	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>0; j--){
			if(v[i][0]==0 || v[0][j]==0){
				v[i][j]=0;			
			}
		}
		if(flag) v[i][0]=0;
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
    rcZero(v);
}