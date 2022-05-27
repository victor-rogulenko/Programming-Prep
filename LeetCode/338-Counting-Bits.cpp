// LeetCode: 338. Counting Bits
// 338-Counting-Bits.cpp
// Created by Victor Rogulenko
// [2022-05-28 00:00]  

// Given an integer n, return an array ans of length n + 1 
// such that for each i (0 <= i <= n), ans[i] is the number of 
// 1's in the binary representation of i.

// Follow up:
// It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

// 0 <= n <= 10^5

#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n+1, 0);
        
        for (int idx = 1; idx <= n; ++idx) {
            int temp = dp[idx >> 1];
            dp[idx] = (idx % 2 == 0 ? temp : temp + 1);
        }
        
        return dp;
    }
};

// #bugs = 0