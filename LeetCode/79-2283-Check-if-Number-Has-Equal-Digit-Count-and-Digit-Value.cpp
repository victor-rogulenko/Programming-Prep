// LeetCode: BW Contest 79, 2283. Check if Number Has Equal Digit Count and Digit Value
// 79-2283-Check-if-Number-Has-Equal-Digit-Count-and-Digit-Value.cpp
// Created by Victor Rogulenko
// May 28, 2022

// You are given a 0-indexed string num of length n consisting of digits.
// Return true if for every index i in the range 0 <= i < n, the digit i 
// occurs num[i] times in num, otherwise return false.

// n == num.length
// 1 <= n <= 10
// num consists of digits.

#include <string>

class Solution {
public:
    bool digitCount(const std::string& num) {
        int cntr[11];
        
        for (int idx = 0; idx <= 10; ++idx) {
            cntr[idx] = 0;
        }
        
        for (int idx = 0; idx < num.size(); ++idx) {
            int val = (int)(num[idx]) - (int)('0');
            ++cntr[val];
        }
        
        for (int idx = 0; idx < num.size(); ++idx) {
            int val = (int)(num[idx]) - (int)('0');
            if (cntr[idx] != val) {
                return false;
            }
        }
        
        return true;
    }
};

// 01234
// 12100
    
// 1210

// #bugs = 0