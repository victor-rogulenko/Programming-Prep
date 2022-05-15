// LeetCode: 53. Maximum Subarray
// 53-Maximum-Subarray.cpp
// Created by Victor Rogulenko
// May 15, 2022

// Given an integer array nums, find the contiguous subarray 
// (containing at least one number) which has the largest sum 
// and return its sum.

// A subarray is a contiguous part of an array.

// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4

#include <vector>
#include <algorithm>

class Solution {
    const int INF = (int)(1e9);
public:
    int maxSubArray(std::vector<int>& nums) {
        int result = -INF;
        int cur = 0;
        for (auto val : nums) {
            cur = std::max(cur+val, val);
            result = std::max(result, cur);
        }
        return result;
    }
};