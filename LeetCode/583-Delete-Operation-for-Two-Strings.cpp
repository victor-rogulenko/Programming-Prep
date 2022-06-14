// LeetCode: 583. Delete Operation for Two Strings
// 583-Delete-Operation-for-Two-Strings.cpp
// Created by Victor Rogulenko
// [2022-06-14 17:42]	

// Given two strings word1 and word2, return the minimum number of steps 
// required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.

// MAJOR IDEA: dp[idx][jdx] = answer when taking the first idx letters from 
// word1 and the first jdx letters from word2. idx and jdx range from 0 to 
// respective word lengths.

#include <vector>
#include <string>
#include <algorithm> //std::min

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        if (word1.length() < word2.length()) {
            std::swap(word1, word2);
        }
        int len1 = word1.length();
        int len2 = word2.length();
        std::vector<std::vector<int>> dp(2, std::vector<int>(len2 + 1));
        
        for (int jdx = 0; jdx <= len2; ++jdx) {
            dp[0][jdx] = jdx;
        }
        
        for (int idx = 1; idx <= len1; ++idx) {
            dp[1][0] = idx;
            for (int jdx = 1; jdx <= len2; ++jdx) {
                dp[1][jdx] = std::min(dp[0][jdx], dp[1][jdx-1]) + 1;
                if (word1[idx-1] == word2[jdx-1]) {
                    dp[1][jdx] = std::min(dp[1][jdx], dp[0][jdx-1]);
                }
            }
            dp[0] = dp[1];
        }
            
        return dp[1][len2];
    }
};

// #bugs = 0

// sea
// eat

// idx = 3
// jdx = 
// dp[0] 2 1 2 3
// dp[1] 3 2 1 2