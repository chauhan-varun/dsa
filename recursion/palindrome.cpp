#include<iostream>
#include<string>
using namespace std;

void isPalindrome(string s, int idx, bool flag){
    if(idx>s.size()){
        cout<<flag;
        return;
    }
    if(s[idx]==s[s.size()-idx-1]) isPalindrome(s, idx+1, true);
    else {
        cout<<false;
        return;
    }
    
}

int main(){
    string s="racecar";
    isPalindrome(s , 0, true);
}