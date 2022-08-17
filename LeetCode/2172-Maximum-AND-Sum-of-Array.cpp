// LeetCode: 2172. Maximum AND Sum of Array
// 2172-Maximum-AND-Sum-of-Array.cpp
// Created by Victor Rogulenko
// [2022-08-17 15:21]	

// You are given an integer array nums of length n and an integer 
// numSlots such that 2 * numSlots >= n. There are numSlots slots 
// numbered from 1 to numSlots.
// You have to place all n integers into the slots such that each slot 
// contains at most two numbers. The AND sum of a given placement is the 
// sum of the bitwise AND of every number with its respective slot number.
// For example, the AND sum of placing the numbers [1, 3] into slot 1 and 
// [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + 
// (6 AND 2) = 1 + 1 + 0 + 2 = 4.
// Return the maximum possible AND sum of nums given numSlots slots.

// n == nums.length
// 1 <= numSlots <= 9
// 1 <= n <= 2 * numSlots
// 1 <= nums[i] <= 15

// MAJOR IDEA: A dynamic programming solution
// State is a bitmask of nums we've allocated (1) or not (0)
// For each bitmask, pick each bit i and try to allocate corresponding nums[i]
// into the rightmost slot given bit count of the bitmask
// result is in the state of 111...111, i.e. (1 << N) - 1
// Time: O(2^(2*numSlots)*numSlots). Space: O(2^(2*numSlots))

#include <vector>
#include <algorithm> // std::max

const int maxSize = (int)(1 << 18);

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        nums.resize(2*numSlots, 0);  // Need this to consider all possible slot sizes
        int N = nums.size();
        int finalState = (1 << N) - 1;
        int dp[maxSize] = {0};
        for (int bitmask = 1; bitmask <= finalState; ++bitmask) {
            // The rightmost slot given the bit count of the bitmask:
            // (there are 2 slots of each size)
            int slotNumber = (__builtin_popcount(bitmask) + 1) / 2; // bitCount
            for (int idx = 0; idx < N; ++idx) { // Iterate through all elements in nums
                if (bitmask & (1 << idx)) { // If the bitmask has this element (this bit)
                    dp[bitmask] = std::max(dp[bitmask], 
                                           dp[bitmask ^ (1 << idx)] + (nums[idx] & slotNumber));
                }
            }
        }
        return dp[finalState];
    }
};