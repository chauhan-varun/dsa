#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long prevNotRobbed = 0;
        long long prevRobbed = nums[0];
        
        for (int i = 1; i < n; ++i) {
            long long currNotRobbed = max(prevNotRobbed, prevRobbed);
            long long currRobbed;
            if (colors[i] == colors[i-1]) {
                currRobbed = (long long)nums[i] + prevNotRobbed;
            } else {
                currRobbed = (long long)nums[i] + max(prevNotRobbed, prevRobbed);
            }
            prevNotRobbed = currNotRobbed;
            prevRobbed = currRobbed;
        }
        
        return max(prevNotRobbed, prevRobbed);
    }
};