// LeetCode: 153. Find Minimum in Rotated Sorted Array
// 153-Find-Minimum-in-Rotated-Sorted-Array.cpp
// Created by Victor Rogulenko
// [2022-06-25 22:35]  

// Suppose an array of length n sorted in ascending order is rotated between 
// 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time 
// results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum 
// element of this array.
// You must write an algorithm that runs in O(log n) time.
// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.

// MAJOR IDEA: Bin search for the rotation point

#include <vector>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left + 1 < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return std::min(nums[0], std::min(nums[left], nums[right]));
    }
};

// #bugs = 1

// left 2
// right 3
// mid 3
// result = 3