// LeetCode: 926. Flip String to Monotone Increasing
// 926-Flip-String-to-Monotone-Increasing.cpp
// Created by Victor Rogulenko
// [2022-06-07 16:18]	

// A binary string is monotone increasing if it consists of some number 
// of 0's (possibly none), followed by some number of 1's (also possibly none).
// You are given a binary string s. You can flip s[i] changing it from 0 to 1 
// or from 1 to 0.
// Return the minimum number of flips to make s monotone increasing.
// 1 <= s.length <= 10^5
// s[i] is either '0' or '1'.

// MAJOR IDEA: 1) Keep track of misplaced zeros and ones, update with each iteration. 
// Result is the min of their sum. Initially, all zeros are mistplaced, and the 
// number of misplaced ones is 0.
// 2) Keep count of ones. ++ans if ch = '0', and then ans = min(ans, ones)

#include <string>

class Solution {
public:
    int minFlipsMonoIncr(const std::string& s) {
        int num_zeros = 0;
        for (auto ch : s) {
            num_zeros += (ch == '0');
        }
        int result = num_zeros;
        int num_ones = 0;
        for (int idx = 0; idx < s.length(); ++idx) {
            num_zeros -= (s[idx] == '0');
            num_ones += (s[idx] == '1');
            result = std::min(result, num_zeros + num_ones);
        }
        return result;
    }
};