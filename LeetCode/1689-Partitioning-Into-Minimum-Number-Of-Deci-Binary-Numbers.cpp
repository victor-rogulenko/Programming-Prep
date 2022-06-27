// LeetCode: 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// 1689-Partitioning-Into-Minimum-Number-Of-Deci-Binary-Numbers.cpp
// Created by Victor Rogulenko
// [2022-06-28 00:32]	

// A decimal number is called deci-binary if each of its digits is either 
// 0 or 1 without any leading zeros. For example, 101 and 1100 are 
// deci-binary, while 112 and 3001 are not.
// Given a string n that represents a positive decimal integer, return 
// the minimum number of positive deci-binary numbers needed so that they 
// sum up to n.

// 1 <= n.length <= 10^5
// n consists of only digits.
// n does not contain any leading zeros and represents a positive integer.

// MAJOR IDEA: Only need as many numbers as the biggest digit.
// We can construct any other digit with the numbers at hand

#include <string>
#include <algorithm> // std::max

class Solution {
public:
    int minPartitions(const std::string& n) {
        int res = 0;
        for (auto ch : n) {
            res = std::max(res, (int)(ch) - (int)('0'));
        }
        return res;
    }
};