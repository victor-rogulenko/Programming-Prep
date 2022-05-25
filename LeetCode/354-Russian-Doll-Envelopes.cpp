// LeetCode: 354. Russian Doll Envelopes
// 354-Russian-Doll-Envelopes.cpp
// Created by Victor Rogulenko
// [2022-05-25 23:47]

// You are given a 2D array of integers envelopes where 
// envelopes[i] = [wi, hi] represents the width and the height 
// of an envelope.
// One envelope can fit into another if and only if both the width 
// and height of one envelope are greater than the other envelope's 
// width and height.
// Return the maximum number of envelopes you can Russian doll 
// (i.e., put one inside the other).
// Note: You cannot rotate an envelope.

// 1 <= envelopes.length <= 10^5
// envelopes[i].length == 2
// 1 <= wi, hi <= 10^5

// MAJOR IDEA: Sort first elm in increasing order and second in decreasing. 
// Store array of second elements: smallest values greater than 
// everything before them. The answer is the size of such an array. 
// However, its elements are not the desired envelopes

// 0         1       2       3       4       5       6       7       8
// [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]

// dp
// 100 200 250 360 380

#include <vector>
#include <algorithm> // std::lower_bound

class Solution {
public:    
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::vector<int> dp;
        std::sort(envelopes.begin(), envelopes.end(), 
                 [](const std::vector<int>& lhs, const std::vector<int>& rhs) 
                 -> bool {
                     return (lhs[0] < rhs[0] || 
                            (lhs[0] == rhs[0] && lhs[1] > rhs[1]));
                 });
        
        for (const auto& env : envelopes) {
            int pos = std::lower_bound(dp.begin(), dp.end(), env[1]) - dp.begin();
            if (pos == dp.size()) {
                dp.push_back(env[1]);
            } else {
                dp[pos] = env[1];
            }
        }
        
        return dp.size();
    }
};

// #bugs: 4