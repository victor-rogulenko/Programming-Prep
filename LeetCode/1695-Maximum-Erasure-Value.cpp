// LeetCode: 1695. Maximum Erasure Value
// 1695-Maximum-Erasure-Value.cpp
// Created by Victor Rogulenko
// [2022-06-12 14:11]	

// You are given an array of positive integers nums and want to erase 
// a subarray containing unique elements. The score you get by erasing the 
// subarray is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// An array b is called to be a subarray of a if it forms a contiguous subsequence 
// of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4

// MAJOR IDEA: Sliding window. Keep an array of seen elements. 
// Move right_ptr until you see a repeating element. Move left_ptr until 
// this same element is not repeated anymore

#include <vector>

const int maxSize = (int)(1e4) + 3;

class Solution {
public:
    int maximumUniqueSubarray(const std::vector<int>& nums) {
        int n = nums.size();
        int cur_sum = 0;
        int result = 0;
        int left_ptr = 0;
        int right_ptr = 0;
        int seen[maxSize] = {0};
        
        while (right_ptr < n) {
            while (right_ptr < n && seen[nums[right_ptr]] == 0) {
                cur_sum += nums[right_ptr];
                ++seen[nums[right_ptr]];
                ++right_ptr;
            }
            result = std::max(result, cur_sum);
            if (right_ptr == n) {
                break;
            }
            while (left_ptr < right_ptr && seen[nums[right_ptr]] > 0) {
                cur_sum -= nums[left_ptr];
                --seen[nums[left_ptr]];
                ++left_ptr;
            }
        }
        return result;
    }
};

// #bugs = 2