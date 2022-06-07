// LeetCode: 696. Count Binary Substrings
// 696-Count-Binary-Substrings.cpp
// Created by Victor Rogulenko
// [2022-06-07 13:12]  

// Given a binary string s, return the number of non-empty substrings 
// that have the same number of 0's and 1's, and all the 0's and all the 1's 
// in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.

// 1 <= s.length <= 10^5
// s[i] is either '0' or '1'.

// MAJOR IDEA: Count rows of same chars. Keep track of prev and cur row lengths. 
// Result += min(prev, cur)

#include <string>

class Solution {
public:
    int countBinarySubstrings(const std::string& s) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        
        int result = 0;
        int prev_row = 0, cur_row = 1;
        for (int idx = 1; idx < s.size(); ++idx) {
            if (s[idx] == s[idx-1]) {
                ++cur_row;
            } else {
                result += std::min(prev_row, cur_row);
                prev_row = cur_row;
                cur_row = 1;
            }
        }
        return result + std::min(prev_row, cur_row);
    }
};

// #bugs = 1

// result = 0
// prev_row = 1
// cur_row = 0

// idx = 2

// "1000111"