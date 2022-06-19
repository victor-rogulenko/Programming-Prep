// LeetCode: 34. Find First and Last Position of Element in Sorted Array
// 34-Find-First-and-Last-Position-of-Element-in-Sorted-Array.cpp
// Created by Victor Rogulenko
// [2022-06-19 15:13]  

// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// 0 <= nums.length <= 10^5
// -109 <= nums[i] <= 10^9
// nums is a non-decreasing array.
// -109 <= target <= 10^9

// MAJOR IDEA: Find lower_bound and upper_bound - 1. Check that lower_bound != end 
// and lower_bound == target

#include <vector>

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        auto upper = std::upper_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower > target) {
            return {-1, -1};
        } else {
            return {(int)(lower - nums.begin()), (int)(upper - 1 - nums.begin())};
        }
    }
};

// #bugs = 2