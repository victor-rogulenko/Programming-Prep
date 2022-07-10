// LeetCode: 746. Min Cost Climbing Stairs
// 746-Min-Cost-Climbing-Stairs.cpp
// Created by Victor Rogulenko
// [2022-07-10 14:33]	

// You are given an integer array cost where cost[i] is the cost of ith step 
// on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

// MAJOR IDEA: DP. dp[idx] = std::min(dp[idx-2] + cost[idx-2], dp[idx-1] + cost[idx-1]);

#include <vector>
#include <algorithm> // std::min

const int maxSize = 1010;

class Solution {
public:
    int minCostClimbingStairs(const std::vector<int>& cost) {
        int costSize = cost.size();
        int dp[maxSize] = {0};
        
        for (int idx = 2; idx <= costSize; ++idx) {
            dp[idx] = std::min(dp[idx-2] + cost[idx-2], dp[idx-1] + cost[idx-1]);
        }
        
        return dp[costSize];
    }
};

// cost = [10,15,20, end]
// dp = [0, 0, 10, 15 ]

// cost = [1,100,1,1,1,100,1,1,100,1, end]
// dp =   [0,  0,1,2,2,  3,3,4,  4,5,   6 ]