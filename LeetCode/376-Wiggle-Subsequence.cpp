// LeetCode: 376. Wiggle Subsequence
// 376-Wiggle-Subsequence.cpp
// Created by Victor Rogulenko
// [2022-07-03 22:49]	

// A wiggle sequence is a sequence where the differences between successive 
// numbers strictly alternate between positive and negative. The first 
// difference (if one exists) may be either positive or negative. A sequence 
// with one element and a sequence with two non-equal elements are trivially 
// wiggle sequences.
// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences 
// (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
// The first is not because its first two differences are positive, and the second 
// is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the 
// original sequence, leaving the remaining elements in their original order.
// Given an integer array nums, return the length of the longest wiggle 
// subsequence of nums.
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000
// Follow up: Could you solve this in O(n) time? 

// MAJOR IDEA 1: O(N^2), DP. For each idx, keep track of the max attainable lengths
// if nums[idx] is a bigger than the previous value and if it is smaller. 
// Update the length by comparing nums[idx] with all previous nums[jdx], jdx < idx

// MAJOR IDEA 2: O(N), DP. up = result if idx wiggled up, down = result if idx wiggled
// down. At each step, if idx wiggles up (nums[idx] > nums[idx-1]), idx-1 must have wiggled
// down, i.e. up = down + 1. If idx wiggles down, down = up + 1

// MAJOR IDEA 3: O(N), Greedy. Count the number of local minima and maxima:
// if ((prevDiff >= 0 && diff < 0) || (prevDiff <= 0 && diff > 0)) {++res; prevDiff = diff};

// SOLUTION 1. O(N^2)

#include <vector>

const int maxSize = 1010;

class Solution {
public:
    int wiggleMaxLength(const std::vector<int>& nums) {
        int prevSmaller[maxSize];
        int prevGreater[maxSize];
        int result = 1;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            prevSmaller[idx] = 1;
            prevGreater[idx] = 1;
            
            for (int jdx = 0; jdx < idx; ++jdx) {
                if (nums[jdx] < nums[idx]) {
                    prevSmaller[idx] = std::max(prevSmaller[idx], prevGreater[jdx] + 1);
                } else if (nums[jdx] > nums[idx]) {
                    prevGreater[idx] = std::max(prevGreater[idx], prevSmaller[jdx] + 1);
                }
            }
            
            result = std::max(result, prevGreater[idx]);
            result = std::max(result, prevSmaller[idx]);
        }
        
        return result;
    }
};

// #bugs = 1

// SOLUTION 2. O(N)

#include <algorithm> // std::max

class Solution2 {
public:
    int wiggleMaxLength(const std::vector<int>& nums) {
        int up = 1, down = 1;
        
        for (int idx = 1; idx < nums.size(); ++idx) {
            if (nums[idx] > nums[idx - 1]) {
                // Wiggles up. Up gets longer, down stays the same
                up = down + 1;
            } else if (nums[idx] < nums[idx - 1]) {
                // Wiggles down. Down gets longer, up stays the same
                down = up + 1;   
            }
        }
        
        return std::max(up, down);
    }
};

// SOLUTION 3. O(N)

class Solution3 {
public:
    int wiggleMaxLength(const std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        int prevDiff = nums[1] - nums[0];
        int result = (prevDiff != 0 ? 2 : 1);
        
        for (int idx = 2; idx < nums.size(); ++idx) {
            int diff = nums[idx] - nums[idx - 1];
            
            if ((prevDiff >= 0 && diff < 0) || 
                (prevDiff <= 0 && diff > 0)) {
                
                ++result;
                prevDiff = diff;
            }
        }
        
        return result;
    }
};