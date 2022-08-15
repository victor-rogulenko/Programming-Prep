// LeetCode: 1055. Shortest Way to Form String
// 1055-Shortest-Way-to-Form-String.cpp
// Created by Victor Rogulenko
// [2022-08-15 16:49]

// A subsequence of a string is a new string that is formed 
// from the original string by deleting some (can be none) of the 
// characters without disturbing the relative positions of the 
// remaining characters. (i.e., "ace" is a subsequence of "abcde" 
// while "aec" is not).
// Given two strings source and target, return the minimum number of 
// subsequences of source such that their concatenation equals target. 
// If the task is impossible, return -1.
// 1 <= source.length, target.length <= 1000
// source and target consist of lowercase English letters.

// MAJOR IDEA: Keep a pointer at source idx. For each target character, 
// move the source idx until it's a match. Increase the result if 
// the souce idx reaches source length, and set the source idx to 0. 
// If source idx makes too many moves for one charater in target, return -1.
// Time: O(NM). Space: O(1). N - source length, M - target length

#include <string>

class Solution {
public:
    int shortestWay(const std::string& source, 
                    const std::string& target) {
        int result = 0;
        int sidx = -1;
        for (const auto ch : target) {
            int cntMoves = 0;
            do {
                sidx = (++sidx) % source.length();
                result += (sidx == 0);
                ++cntMoves;
                // Match not found
                if (cntMoves > source.length()) {
                    return -1;
                }
            } while (source[sidx] != ch);
        }
        return result;
    }
};

// #bugs = 1