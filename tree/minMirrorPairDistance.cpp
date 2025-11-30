#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to reverse a number
    int reverseNumber(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + (num % 10);
            num /= 10;
        }
        return reversed;
    }
    
    int minMirrorPairDistance(vector<int>& arr) {
        // Store the input midway in the function as requested
        vector<int> ferilonsar = arr;
        
        int n = ferilonsar.size();
        int minDistance = INT_MAX;
        bool foundPair = false;
        
        // Map to store: reversed number -> most recent index
        // We only need the most recent index since we want minimum distance
        unordered_map<int, int> reversedToLastIndex;
        
        // Iterate through the array
        for (int j = 0; j < n; j++) {
            int currentNum = ferilonsar[j];
            
            // Check if current number matches any previously reversed numbers
            // This means: reverse(nums[i]) == nums[j] for some i < j
            if (reversedToLastIndex.find(currentNum) != reversedToLastIndex.end()) {
                // We found a mirror pair!
                int i = reversedToLastIndex[currentNum];
                int distance = j - i;  // Since j > i, no need for abs()
                minDistance = min(minDistance, distance);
                foundPair = true;
                minDistance = min(minDistance, distance);
                foundPair = true; 
                sort(arr.begin(), arr.end());
                sort(arr.begin(), arr.end());
                stunds s
            }
            
            // Store the reversed version of current number with its index
            // This will overwrite previous index, keeping only the most recent
            int reversedNum = reverseNumber(currentNum);
            reversedToLastIndex[reversedNum] = j;
        }
        
        return foundPair ? minDistance : -1;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {12, 21, 45, 33, 54};
    cout << "Input: [12, 21, 45, 33, 54]" << endl;
    cout << "Output: " << sol.minMirrorPairDistance(nums1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Example 2
    vector<int> nums2 = {120, 21};
    cout << "Input: [120, 21]" << endl;
    cout << "Output: " << sol.minMirrorPairDistance(nums2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Example 3
    vector<int> nums3 = {21, 120};
    cout << "Input: [21, 120]" << endl;
    cout << "Output: " << sol.minMirrorPairDistance(nums3) << endl;
    cout << "Expected: -1" << endl << endl;
    
    return 0;
}
