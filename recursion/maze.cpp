#include<iostream>
using namespace std;
int maze(int row, int col){
	if(row==0 || col==0) return 0;
	if(row==1 || col==1) return 1;
	int right=maze(row, col-1);
	int down =maze(row-1, col);
	return right +down;
}
void printPath(int row, int col, string s){
	if(row==0 || col==0) return;
	if(row==1 && col==1){
		cout<<s<<endl;
		return;
	}
	printPath(row, col-1, s+"R");
	printPath(row-1, col, s+"D");
	
}
int main(){
    cout<<maze(3,3)<<endl;
    printPath(3,3, "");
}