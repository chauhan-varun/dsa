#include<iostream>
#include<vector>
using namespace std;
void multiply(vector<int> &result, int x){
	int carry=0;
	for(int i=0; i<result.size(); i++){
		int product= result[i] * x + carry;
		result[i]=product%10;
		carry=product/10;
	}
	while(carry){
		result.push_back(carry%10);
		carry/=10;
	}
}
void factorial(int num){
	vector<int> result;
	result.push_back(1);
	for(int i=2; i<=num; i++){
		multiply(result,i);
	}
	for(int i=result.size()-1; i>=0; i--){
		cout<<result[i];
	}
}


int main(){
	int num=100;
	factorial(num);
}