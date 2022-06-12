// LeetCode: 2104. Sum of Subarray Ranges
// 2104-Sum-of-Subarray-Ranges.cpp
// Created by Victor Rogulenko
// [2022-06-12 19:14]	

// You are given an integer array nums. The range of a subarray of nums 
// is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.
// 1 <= nums.length <= 1000
// -10^9 <= nums[i] <= 10^9
// Follow-up: Could you find a solution with O(n) time complexity?

// MAJOR IDEA. 1) Straightforward 2 iterators. O(N^2)
// 2) Sum up all maxima and subtract all minima. Do max and min separately.
// Keep a stack of strictly increasing maxima (or strictly decreasing minima),
// add to the result when poping from stack, then add current idx to stack. O(N)

// SOLUTION 1. 2 iterators keeping track of current min and max.

#include <vector>

class Solution {
public:
    long long subArrayRanges(const std::vector<int>& nums) {
        long long result = 0;
        for (int left = 0; left < nums.size(); ++left) {
            int min_val = nums[left];
            int max_val = nums[left];
            for (int right = left; right < nums.size(); ++right) {
                min_val = std::min(min_val, nums[right]);
                max_val = std::max(max_val, nums[right]);
                result += max_val - min_val;
            }
        }
        return result;
    }
};

// SOLUTION 2. Sum up all maxima and subtract all minima

class Solution2 {
public:
    template <class Compare>
    long long subArrayExtrema(const std::vector<int>& nums, Compare comp) {
        // Find the sum of all maxima or all minima (depending on comp)
        long long result = 0;
        int n = nums.size();
        std::stack<int> indices;
        for (int idx = 0; idx <= n; ++idx) {
            while (!indices.empty() && 
                   (idx == n || comp(nums[indices.top()], nums[idx]))) {
                int jdx = indices.top();
                indices.pop();
                int kdx = (indices.empty() ? -1 : indices.top());
                // nums[jdx] is the extremum for all subarrays starting
                // between kdx and jdx and ending between jdx and idx
                result += ((long)(nums[jdx]) * (idx - jdx) * (jdx - kdx));
            }
            indices.push(idx);
        }        
        return result;
    }
        
    long long subArrayRanges(const std::vector<int>& nums) {
        return subArrayExtrema(nums, std::less()) -  // Sum up all maximums
               subArrayExtrema(nums, std::greater()); // Subtract all minimums
    }
};