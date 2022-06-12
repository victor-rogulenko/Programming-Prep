// LeetCode: 1567. Maximum Length of Subarray With Positive Product
// 1567-Maximum-Length-of-Subarray-With-Positive-Product.cpp
// Created by Victor Rogulenko
// [2022-06-12 15:32]	

// Given an array of integers nums, find the maximum length of a subarray 
// where the product of all its elements is positive.
// A subarray of an array is a consecutive sequence of zero or more values taken 
// out of that array.
// Return the maximum length of a subarray with positive product.
// 1 <= nums.length <= 10^5
// -109 <= nums[i] <= 10^9

// MAJOR IDEA: Split nums into nonzero segments. In each segment, count # of negative elements. If it's
// even, update the ans with the size of the segment. If it's odd, try removing 
// the first and the last negative element and see which gives a higher result

#include <vector>
#include <algorithm> // std::max

class Solution {
public:
    int findNextZero(const std::vector<int>& nums, int left) {
        int nextZero = left + 1;
        while (nextZero < nums.size() && nums[nextZero] != 0) {
            ++nextZero;
        }
        return nextZero;
    }
    
    int getMaxLenWithinBoundaries(const std::vector<int>& nums,
                                 int left, int right) {
        int cnt_neg = 0;
        int left_neg = -1, right_neg = -1;
        
        for (int idx = left; idx < right; ++idx) {
            if (nums[idx] < 0) {
                ++cnt_neg;
                if (left_neg == -1) {
                    left_neg = idx;
                }
                right_neg = idx;
            }
        }
        if (cnt_neg % 2 == 0) {
            return right - left;
        }
        
        return std::max(right - left_neg - 1, right_neg - left);
    }
    
    int getMaxLen(const std::vector<int>& nums) {
        int left = 0;
        int result = 0;
        
        while (left < nums.size()) {
            while (left < nums.size() && nums[left] == 0) {
                ++left;
            }
            if (left == nums.size()) {
                break;
            }
            
            int right = findNextZero(nums, left);
            int candidate = getMaxLenWithinBoundaries(nums, left, right);
            result = std::max(result, candidate);
            left = right + 1;
        }
        return result;
    }
};

// #bugs = 3