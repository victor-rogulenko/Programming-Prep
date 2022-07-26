// LeetCode: 2178. Maximum Split of Positive Even Integers
// 2178-Maximum-Split-of-Positive-Even-Integers.cpp
// Created by Victor Rogulenko
// July 26, 2022

// You are given an integer finalSum. Split it into a sum of a maximum number 
// of unique positive even integers.
// For example, given finalSum = 12, the following splits are valid (unique positive 
// even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). 
// Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum 
// cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
// Return a list of integers that represent a valid split containing a maximum number 
// of integers. If no valid split exists for finalSum, return an empty list. You may 
// return the integers in any order.

// MAJOR IDEA: Greedy. Pick the first distinct even integers until you no longer can

#include <vector>

class Solution {
public:
    std::vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) {
            return std::vector<long long>{};
        };
        
        std::vector<long long> result;
        long long cur = 2;
        while (finalSum - cur > cur) {
            result.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        
        result.push_back(finalSum);
        return result;
    }
};

// finalSum = 6
// cur = 6
// 2 4