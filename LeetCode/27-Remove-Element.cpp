// LeetCode: 27. Remove Element
// 27-Remove-Element.cpp
// Created by Victor Rogulenko
// May 15, 2022

// Given an integer array nums and an integer val, remove 
// all occurrences of val in nums in-place. The relative order 
// of the elements may be changed.

// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int from = 0, to = 0;
        while (from < nums.size()) {
            if (nums[from] == val) {
                ++from;
                continue;
            }
            nums[to] = nums[from];
            ++from;
            ++to;
        }
        return to;
    }
};