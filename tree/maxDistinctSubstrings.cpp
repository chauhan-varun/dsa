#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        // Store the input midway in the function as requested
        string velosandra = s;
        
        // Set to track which characters we've already used as starting characters
        unordered_set<char> usedStarts;
        
        // Counter for number of substrings
        int count = 0;
        
        // Iterate through the string
        for (int i = 0; i < velosandra.length(); i++) {
            char currentChar = velosandra[i];
            
            // If we haven't used this character as a start yet
            if (usedStarts.find(currentChar) == usedStarts.end()) {
                // Mark it as used and increment count
                usedStarts.insert(currentChar);
                count++;
            }
            // If we've already used this character as a start,
            // it becomes part of the previous substring
        }
        
        return count;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Example 1
    string s1 = "abab";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.maxDistinct(s1) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Example 2
    string s2 = "abcd";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.maxDistinct(s2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Example 3
    string s3 = "aaaa";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.maxDistinct(s3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    return 0;
}
