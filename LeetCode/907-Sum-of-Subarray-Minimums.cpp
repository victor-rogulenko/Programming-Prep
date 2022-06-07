// LeetCode: 907. Sum of Subarray Minimums
// 907-Sum-of-Subarray-Minimums.cpp
// Created by Victor Rogulenko
// [2022-06-07 15:42]

// Given an array of integers arr, find the sum of min(b), where b ranges 
// over every (contiguous) subarray of arr. Since the answer may be large, 
// return the answer modulo 10^9 + 7.

// 1 <= arr.length <= 3 * 10^4
// 1 <= arr[i] <= 3 * 10^4

// MAJOR IDEA: For each element, find its closest smaller neighbor on the left, nb. 
// Then dp[idx] = dp[nb] + (idx - nb) * arr[idx]
// All substrings to the left of nb will contribute dp[nb] to dp[idx] combined,
// All substrings to the right of nb will contribute arr[idx] each.
// Can do the same via a stack

#include <vector>

class Solution {
    const int modulo = (int)(1e9) + 7;
    const int maxArrSize = 3 * (int)(1e4) + 10;
public:
    int sumSubarrayMins(const std::vector<int>& arr) {
        int closest_smaller_value_on_the_left[maxArrSize];
        closest_smaller_value_on_the_left[0] = -1;
        int n_words = arr.size();
        
        for (int idx = 1; idx < n_words; ++idx) {
            int jdx = idx - 1;
            while (jdx >= 0 && arr[jdx] >= arr[idx]) {
                jdx = closest_smaller_value_on_the_left[jdx];
            }
            closest_smaller_value_on_the_left[idx] = jdx;
        }
        
        int dp[maxArrSize];
        for (int idx = 0; idx < n_words; ++idx) {
            if (closest_smaller_value_on_the_left[idx] == -1) {
                dp[idx] = (idx + 1) * arr[idx];
            } else {
                dp[idx] = dp[closest_smaller_value_on_the_left[idx]] +
                    (idx - closest_smaller_value_on_the_left[idx]) * arr[idx];
            }    
        }
        
        int result = 0;
        for (int idx = 0; idx < n_words; ++idx) {
            result += dp[idx];
            result %= modulo;
        }
        
        return result;
    }
};

// #bugs = 4

// cur_sum = 3 5
// res = 5
// idx = 2
// st: {1, 1}