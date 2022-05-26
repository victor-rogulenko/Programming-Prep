// LeetCode: 300. Longest Increasing Subsequence
// 300-Longest-Increasing-Subsequence.cpp
// Created by Victor Rogulenko
// [2022-05-26 14:11]	

// Given an integer array nums, return the length of the longest strictly 
// increasing subsequence.
// A subsequence is a sequence that can be derived from an array by 
// deleting some or no elements without changing the order of the remaining 
// elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4

// MAJOR IDEA: Store array of elements from the input: 
// smallest values greater than everything before them. 
// The answer is the size of such an array. 

#include <vector>
#include <algorithm> // std::lower_bound

const int nMax = 2501;

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int dp[nMax];
        int array_size = 0;
        for (const auto elm : nums) {
            int pos = std::lower_bound(dp, dp + array_size, 
                                       elm) - dp;
            if (pos == array_size) {
                ++array_size;
                dp[array_size - 1] = elm;
            } else {
                dp[pos] = elm;    
            }
        }
        return array_size;
    }
};

// [10,9,2,5,3,7,101,18]
// dp = 2,3,7,18

// #bugs = 0