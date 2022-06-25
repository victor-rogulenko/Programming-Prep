
// LeetCode: 665. Non-decreasing Array
// 665-Non-decreasing-Array.cpp
// Created by Victor Rogulenko
// [2022-06-25 21:57]	

// Given an array nums with n integers, your task is to check 
// if it could become non-decreasing by modifying at most one element.
// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds 
// for every i (0-based) such that (0 <= i <= n - 2).

// n == nums.length
// 1 <= n <= 10^4
// -10^5 <= nums[i] <= 10^5

// MAJOR IDEA: If next elm is smaller than current, then check: 
// 1) if next elm is smaller than previous, set next elm = cur, 
// 2) else set cur elm = next elm. Do this once only. Otherwise, return false

#include <vector>

class Solution {
public:
    bool checkPossibility(const std::vector<int>& nums) {
        bool marker = false;
        int size = nums.size();
        int prev = nums[0];
        
        for (int idx = 1; idx < size; ++idx) {
            if (nums[idx] < prev) {
                if (marker) {
                    return false;
                }
                marker = true;
                
                if (idx > 1 && nums[idx] < nums[idx-2]) {
                    // nums[idx] = nums[idx-1];
                    // Don't need to change nums
                    // Just keep track of the right prev
                    // In this case, prev remains nums[idx-1]
                    continue;
                } //else {
                  //  nums[idx-1] = nums[idx];    
                //}
            }
            prev = nums[idx];
        }
        return true;
    }
};

// #bugs = 1

// [3,4,2,3]
// [1,4,2,3]
// [3,4,2,5]