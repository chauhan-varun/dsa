#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    int noe=n*n;
    int count=1;
    int minr=0, minc=0, maxc=n-1, maxr=n-1; 
	while(minr<=maxr && minc<=maxc){
		for(int j=minc; j<=maxc && count<=noe; j++){
			arr[minr][j]=count;
			count++;
		}
		minr++;
		for(int i=minr; i<=maxr && count<=noe; i++){
			arr[i][maxc]=count;
			count++;
		}
		maxc--;
		for(int j=maxc; j>=minc && count<=noe; j--){
			arr[maxr][j]=count;
			count++;
		}
		maxr--;
		for(int i=maxr; i>=minr && count<=noe; i-- ){
			arr[i][minc]=count;
			count++;
		}
		minc++;
		
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}