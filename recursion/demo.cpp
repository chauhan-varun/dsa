#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

void rev(vector<int> &arr, int i){
    if(i>=(arr.size()/2))
        return;
    swap(arr[i], arr[arr.size()-i-1]);
    rev(arr, i+1);
}

bool palindrome(string &s, int i){
    if(i>=s.size())
        return true;

    if(s[i]!=s[s.size()-1-i])
        return false;

    return palindrome(s, i+1);
}

int main() {
    vector<int> arr = {6,5,4,3,2,1};
    rev(arr, 0);
    string s = "mada";
    cout<< palindrome(s, 0);
}
