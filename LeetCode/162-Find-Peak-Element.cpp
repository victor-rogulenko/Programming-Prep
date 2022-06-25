// LeetCode: 162. Find Peak Element
// 162-Find-Peak-Element.cpp
// Created by Victor Rogulenko
// [2022-06-25 23:15]	

// A peak element is an element that is strictly greater than its neighbors.
// Given an integer array nums, find a peak element, and return its index. 
// If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞.
// You must write an algorithm that runs in O(log n) time.
// 1 <= nums.length <= 1000
// -2^31 <= nums[i] <= 2^31 - 1
// nums[i] != nums[i + 1] for all valid i.

// MAJOR IDEA: Bin search if nums[mid] > nums[mid - 1], then left = mid,
// else right = mid - 1;

#include <vector>

class Solution {
public:
    int findPeakElement(const std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left != right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > nums[mid - 1]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;      
    }
};

// #bugs = 1

// left = 1
// right = 2
// mid = 2
