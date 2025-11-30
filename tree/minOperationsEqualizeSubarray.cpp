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