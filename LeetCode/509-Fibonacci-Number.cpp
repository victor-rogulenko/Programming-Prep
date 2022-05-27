// LeetCode: 509. Fibonacci Number
// 509-Fibonacci-Number.cpp
// Created by Victor Rogulenko
// [2022-05-28 00:06]  

// Given n, calculate the n-th Fibonacci number F(n).

class Solution {
public:
    int fib(int n) {
        int dp[31];
        dp[0] = 0;
        dp[1] = 1;
        
        for (int idx = 2; idx <= n; ++idx) {
            dp[idx] = dp[idx-1] + dp[idx-2];
        }
        
        return dp[n];
    }
};

// #bugs = 0