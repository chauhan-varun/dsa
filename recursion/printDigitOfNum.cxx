#include<iostream>
using namespace std;
void print (int num){
	if(num==0) return;
	int min =num/10;
	print(min);
	int ld =num%10;
	cout<<ld<< endl;
	

}
int main(){
    int num=654;
    print(num);
}