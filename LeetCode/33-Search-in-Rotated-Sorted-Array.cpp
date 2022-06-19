// LeetCode: 33. Search in Rotated Sorted Array
// 33-Search-in-Rotated-Sorted-Array.cpp
// Created by Victor Rogulenko
// [2022-06-19 16:29]  

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown 
// pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], 
// nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return 
// the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// MAJOR IDEA: Bin search to find the rotation point. Then bin search on 2 segments

#include <vector>
#include <algorithm> // std::lower_bound

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // Find rotation point
        auto it = findRotationPoint(nums.begin(), nums.end());
        
        // Find target in left and right parts
        auto left_result = std::lower_bound(nums.begin(), it, target);
        auto right_result = std::lower_bound(it, nums.end(), target);
        
        if (left_result != nums.end() && *left_result == target) {
            return (int)(left_result - nums.begin());
        } 
        
        if (right_result != nums.end() && *right_result == target) {
            return (int)(right_result - nums.begin());
        }
        
        return -1;
    }
    
private:
    std::vector<int>::iterator findRotationPoint(
        std::vector<int>::iterator start, std::vector<int>::iterator finish) {
        
        if (start == finish || *(finish-1) > *start) {
            return finish;
        }
        
        while (start + 1 != finish) {
            auto mid = start + (finish - start + 1) / 2;
            if (*start > *mid) {
                finish = mid;
            } else {
                start = mid;
            }
        }
        
        return finish;
    }
};

// #bugs = 0

// [4,5,6,(7),0,(1),2]
// start = 3
// finish = 4
// mid = 4