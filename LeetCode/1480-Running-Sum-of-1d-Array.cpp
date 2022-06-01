// LeetCode: 1480. Running Sum of 1d Array
// 1480-Running-Sum-of-1d-Array.cpp
// Created by Victor Rogulenko
// [2022-06-01 22:58]

// Given an array nums. We define a running sum of an array as 
// runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.

// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6

#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int prev = 0;
        for (auto& elm : nums) {
            elm += prev;
            prev = elm;
        }
        return nums;
    }
};