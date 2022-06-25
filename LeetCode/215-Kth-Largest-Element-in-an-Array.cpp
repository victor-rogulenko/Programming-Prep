// LeetCode: 215. Kth Largest Element in an Array
// 215-Kth-Largest-Element-in-an-Array.cpp
// Created by Victor Rogulenko
// [2022-06-25 20:15]	

// Given an integer array nums and an integer k, return the kth 
// largest element in the array.
// Note that it is the kth largest element in the sorted order, 
// not the kth distinct element.
// 1 <= k <= nums.length <= 10^4
// -104 <= nums[i] <= 10^4

// MAJOR IDEA: Use std::partial_sort (not just std::sort) or 
// std::priority_queue (max heap)

#include <vector>
#include <algorithm> // std::partial_sort

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::partial_sort(nums.begin(), 
                          nums.begin() + k, 
                          nums.end(), std::greater<int>());
        return (nums[k - 1]);
    }
};