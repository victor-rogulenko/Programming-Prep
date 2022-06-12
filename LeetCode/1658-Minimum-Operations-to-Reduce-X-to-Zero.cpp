// LeetCode: 1658. Minimum Operations to Reduce X to Zero
// 1658-Minimum-Operations-to-Reduce-X-to-Zero.cpp
// Created by Victor Rogulenko
// [2022-06-12 13:11]	

// You are given an integer array nums and an integer x. In one operation, 
// you can either remove the leftmost or the rightmost element from the array 
// nums and subtract its value from x. Note that this modifies the array for future 
// operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, 
// otherwise, return -1.
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9

// MAJOR IDEA: 1) Build a hash map of (values : # ops) obtained by shifting the right ptr.
// Iterate over possible shift of left ptr and check if there's a corresponding number
// adding up to x in the map. Return the # of operations from left ptr + the map
// 2) Sliding window. Move right_ptr to the left until cur_sum > x. Then move left_ptr
// and right_ptr to the right simultaneously, checking if cur_sum == x and updating
// the result when needed.

// SOLUTION 1. Hash Map

#include <vector>
#include <unordered_map>

const int INF = (int)(1e6);

class Solution {
public:
    int minOperations(const std::vector<int>& nums, int x) {
        std::unordered_map<int, int> right_sum;
        
        int cur_sum_right = 0;
        int ops_right = 0;
        right_sum.insert({0,0});
        
        for (int idx = nums.size()-1; idx >= 0; --idx) {
            cur_sum_right += nums[idx];
            ++ops_right;
            right_sum.insert({cur_sum_right, ops_right});
        }
        
        int result = INF;
        int cur_num_left = 0;
        int ops_left = 0;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            auto right_summand = right_sum.find(x - cur_num_left);
            if (right_summand != right_sum.end()) {
                result = std::min(result, ops_left + right_summand->second);
            }
            cur_num_left += nums[idx];
            ++ops_left;
        }
        return (result > nums.size() ? -1 : result);
    }
};

// #bugs = 2

// SOLUTION 2. Sliding window

class Solution2 {
public:
    int minOperations(const std::vector<int>& nums, int x) {
        int cur_sum = 0;
        int n = nums.size();
        int left_ptr = 0;
        int right_ptr = n - 1;
        int result = n + 1;
        
        while (right_ptr >= 0 && cur_sum < x) {
            cur_sum += nums[right_ptr];
            if (cur_sum == x) {
                result = n - right_ptr;
            }
            --right_ptr;
        }
        
        if (right_ptr < 0 && cur_sum < x) {
            return -1;
        }
        ++right_ptr;
        
        while (left_ptr < n) {
            cur_sum += nums[left_ptr];
            while (right_ptr < n && cur_sum > x) {
                cur_sum -= nums[right_ptr];
                ++right_ptr;
            }
            if (cur_sum == x) {
                result = std::min(result, left_ptr + 1 + (n - right_ptr));
            }
            ++left_ptr;
        }
        return (result <= n ? result : -1);
    }
};