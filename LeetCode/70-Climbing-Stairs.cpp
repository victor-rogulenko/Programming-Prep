// LeetCode: 70. Climbing Stairs
// 70-Climbing-Stairs.cpp
// Created by Victor Rogulenko
// [2022-05-27 23:46]  

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct 
// ways can you climb to the top?

// 1 <= n <= 45

const int nMax = 45;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        
        int dp[nMax+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int floor = 2; floor <= n; ++floor) {
            dp[floor] = dp[floor-1] + dp[floor-2];
        }

        return dp[n];
    }
};

// #bugs = 0