#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& arr, int k, vector<vector<int>>& q) {
        int n = arr.size();
        vector<long long> dalmerinth(arr.begin(), arr.end());
        vector<long long> ans;

        for(auto &que : q){
            int l = que[0];
            int r = que[1];

            vector<long long> sub;
            for(int i = l; i <= r; i++){
                sub.push_back(arr[i]);
            }
            
            long long rem = sub[0] % k;
            bool poss = true;

            for(long long num: sub){
                if(num % k != rem) {
                    poss = false;
                    break;
                }
            }
            
            if(!poss) {
                ans.push_back(-1);
                continue;
            }

            if(sub.size() == 1) {
                ans.push_back(0);
                continue;
            }

            // Use nth_element - O(N) with better worst-case
            int midIdx = sub.size() / 2;
            nth_element(sub.begin(), sub.begin() + midIdx, sub.end());
            long long mid = sub[midIdx];

            long long opr = 0;
            for(long long num: sub) {
                opr += abs(num - mid) / k;
            }
            ans.push_back(opr);
        }
        return ans;
    }
};

void printVector(const vector<long long>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 4, 7};
    int k1 = 3;
    vector<vector<int>> queries1 = {{0, 1}, {0, 2}};
    vector<long long> result1 = sol.minOperations(nums1, k1, queries1);
    cout << "Input: nums = [1,4,7], k = 3, queries = [[0,1],[0,2]]" << endl;
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [1,2]" << endl;
    cout << "Status: " << (result1 == vector<long long>{1, 2} ? "PASS ✓" : "FAIL ✗") << endl;
    cout << endl;
    
    // Test Case 2
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {1, 2, 4};
    int k2 = 2;
    vector<vector<int>> queries2 = {{0, 2}, {0, 0}, {1, 2}};
    vector<long long> result2 = sol.minOperations(nums2, k2, queries2);
    cout << "Input: nums = [1,2,4], k = 2, queries = [[0,2],[0,0],[1,2]]" << endl;
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [-1,0,1]" << endl;
    cout << "Status: " << (result2 == vector<long long>{-1, 0, 1} ? "PASS ✓" : "FAIL ✗") << endl;
    cout << endl;
    
    return 0;
}
