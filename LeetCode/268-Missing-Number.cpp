// LeetCode: 268. Missing Number
// 268-Missing-Number.cpp

// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

// Follow up: Could you implement a solution using only O(1) 
// extra space complexity and O(n) runtime complexity?

// n == nums.length
// 1 <= n <= 10^4
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

// MAJOR IDEA: Approach 1.XOR all numbers 0 to n and all values of arr. 
// Each number present will XOR twice, hence disappear. 
// The missing number will XOR once, hence will stay
// Approach 2. Res = n(n+1)/2 - actual sum

#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int result = nums.size();
        for (int idx = 0; idx < nums.size(); ++idx) {
            result ^= nums[idx];
            result ^= idx;
        }
        return result;
    }
};

// #bugs = 0