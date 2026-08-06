#include<iostream>
using namespace std;
void swap(int* x, int *y){
	int temp = *x;
	*x=*y;
	*y=temp;
	return;
}
int main(){
	int a=2;
	int b=5;
	int* p1=&a;
	int* p2=&b;
	swap(p1,p2);
	cout<<a<<" "<<b;
}