//generate all binary string of length n without consecutive 1's
#include<iostream>
using namespace std;
void binaryStrings(string s, int n){
    if(n==0){
        cout<<s<<endl;
        return;
    }
    binaryStrings(s+"0", n-1);
    if(s=="" || s[s.length()-1]=='0'){
        binaryStrings(s+"1", n-1);
    }

}

int main(){
    int n=3;
    binaryStrings("", n);
}