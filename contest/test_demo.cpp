#include <iostream>
#include <vector>
#include <cassert>
#include "demo.cpp"

void test() {
    Solution sol;
    
    // Example 1
    {
        vector<int> nums = {1, 4, 3, 5};
        vector<int> colors = {1, 1, 2, 2};
        assert(sol.rob(nums, colors) == 9);
        std::cout << "Test Case 1 Passed" << std::endl;
    }
    
    // Example 2
    {
        vector<int> nums = {3, 1, 2, 4};
        vector<int> colors = {2, 3, 2, 2};
        assert(sol.rob(nums, colors) == 8);
        std::cout << "Test Case 2 Passed" << std::endl;
    }
    
    // Example 3
    {
        vector<int> nums = {10, 1, 3, 9};
        vector<int> colors = {1, 1, 1, 2};
        assert(sol.rob(nums, colors) == 22);
        std::cout << "Test Case 3 Passed" << std::endl;
    }
}

int main() {
    test();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
