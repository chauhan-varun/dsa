#include <bits/stdc++.h>
using namespace std;
// vector<string> AllPossibleStrings(string s) {
//     int n = s.size();
//     vector<string> ans;
//     for(int i =1; i<(1<<n); i++){
//         string subStr = "";
//         for(int j =0; j<n; j++){
//             if(i&(1<<j)){
//                 subStr+=s[j];
//             }
//         }
//         ans.push_back(subStr);
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
// }
vector<string> AllPossibleStrings(string s) {
    int n = s.size();
    vector<string> ans;
    
    function<void(int, string)> generate = [&](int i, string subStr){
        if(i==n) {
            if(!subStr.empty()){
                ans.push_back(subStr);
            }
            return;
        }
        
        generate(i+1, subStr + s[i]);
        generate(i+1, subStr);
    };
    generate(0, "");
    sort(ans.begin(), ans.end());
    return ans;
}

