// LeetCode: 462. Minimum Moves to Equal Array Elements II
// 462-Minimum-Moves-to-Equal-Array-Elements-II.cpp
// Created by Victor Rogulenko
// [2022-06-30 13:13]  

// Given an integer array nums of size n, return the minimum number 
// of moves required to make all array elements equal.
// In one move, you can increment or decrement an element of the array by 1.
// Test cases are designed so that the answer will fit in a 32-bit integer.

// n == nums.length
// 1 <= nums.length <= 10^5
// -109 <= nums[i] <= 10^9

// MAJOR IDEA: Equate all elements to the median

#include <vector>
#include <algorithm> // std::nth_element
#include <cmath> // std::abs

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        // Find the median
        auto median_iter = nums.begin() + nums.size()/2;
        std::nth_element(nums.begin(), median_iter, nums.end());
        int median = nums[nums.size() / 2];
        
        // Check adjusting all to median
        int result = 0;
        for (auto num : nums) {
            result += std::abs(num - median);
        }
                
        return result;
    }
};

// #bugs = 1

// 1, 100, 100, 100, 100
// res = 99

// 1 1 10 10 100 100 100

// 0 0 0 100 100
// 0 0 100 100 100