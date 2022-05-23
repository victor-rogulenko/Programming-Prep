// LeetCode: 474. Ones and Zeroes
// 474-Ones-and-Zeroes.cpp
// Created by Victor Rogulenko
// [2022-05-23 14:11]	

// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at 
// most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100

// dp[idx][zeros_cnt][ones_cnt] = max subset with at most zero_cnt zeros
// and at most ones_cnt ones of strings up to idx
// O(m x n x strs.legnth)

class Solution {
public:
    int countChInString(const std::string& str, char ch) {
        int result = 0;
        for (const auto& ch_cur : str) {
            result += (ch_cur == ch);
        }
        return result;
    }
    
    int findMaxForm(const std::vector<std::string>& strs, 
                    int max_zeros, int max_ones) {
        int result = 0;
        int dp[105][105] = {};
        
        for (const auto& cur_str : strs) {
            int cnt_ones = countChInString(cur_str, '1');
            int cnt_zeros = cur_str.size() - cnt_ones;
            
            for (int zr = max_zeros; zr >= 0; --zr) {
                for (int one = max_ones; one >= 0; --one) {
                    if (zr - cnt_zeros >= 0 && one - cnt_ones >= 0 &&
                       dp[zr][one] < dp[zr - cnt_zeros][one - cnt_ones] + 1) {
                        
                        dp[zr][one] = dp[zr - cnt_zeros][one - cnt_ones] + 1;
                        result = std::max(result, dp[zr][one]);
                    }
                }
            }
        }
        
        return result;
    }
};

// 2