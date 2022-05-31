// LeetCode: 1461. Check If a String Contains All Binary Codes of Size K
// 1461-Check-If-a-String-Contains-All-Binary-Codes-of-Size-K.cpp
// Created by Victor Rogulenko
// [2022-05-31 14:31]  

// Given a binary string s and an integer k, return true if every 
// binary code of length k is a substring of s. Otherwise, return false.

// 1 <= s.length <= 5 * 10^5
// s[i] is either '0' or '1'.
// 1 <= k <= 20

// MAJOR IDEA: Update cur_val with every move of the ptr. 
// Mark check[cur_val] = true. Then see if everything in 'check' is true

#include <string>

class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        bool* check = new bool[(1 << k) + 1];
        for (int idx = 0; idx < (1 << k); ++idx) {
            check[idx] = false;
        }
        
        int cur_val = 0;
        int finish = 0;
        
        while (finish < k && finish < s.size()) {
            cur_val = cur_val << 1;
            cur_val += (int)(s[finish]) - (int)('0');
            ++finish;
        }
        check[cur_val] = true;
        
        while (finish < s.size()) {
            cur_val -= ((int)(s[finish - k]) - (int)('0')) * (1 << (k-1));
            cur_val = cur_val << 1;
            cur_val += (int)(s[finish]) - (int)('0');
            check[cur_val] = true;
            ++finish;
        }
        
        for (int idx = 0; idx < (1 << k); ++idx) {
            if (!check[idx]) {
                delete []check;
                return false;
            }
        }
        delete []check;
        return true;
    }
};

// 00110110
// k = 2
// finish = 4
// cur_val = 1
// 0 -> true
// 1 -> true
// 2
// 3 

// #bugs = 0