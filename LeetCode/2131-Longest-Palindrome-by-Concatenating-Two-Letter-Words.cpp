// LeetCode: 2131. Longest Palindrome by Concatenating Two Letter Words
// 2131-Longest-Palindrome-by-Concatenating-Two-Letter-Words.cpp
// Created by Victor Rogulenko
// June 29, 2022

// You are given an array of strings words. Each element of words consists of 
// two lowercase English letters.
// Create the longest possible palindrome by selecting some elements from words 
// and concatenating them in any order. Each element can be selected at most once.
// Return the length of the longest palindrome that you can create. If it is 
// impossible to create any palindrome, return 0.
// A palindrome is a string that reads the same forward and backward.
// 1 <= words.length <= 10^5
// words[i].length == 2
// words[i] consists of lowercase English letters.

// MAJOR IDEA: Count the numbers of all 26*26 2-char combinations. 
// Iterate through all combinations and increase the answer by the min of 
// a given combination count and its reverse. Careful with double chars

#include <vector>
#include <string>

const int alphabetSize = 26;
const char firstLetter = 'a';

class Solution {
public:
    int longestPalindrome(const std::vector<std::string>& words) {
        // Build a matrix of counts of all possible words
        int counts[alphabetSize][alphabetSize] = {0};
        for (auto& word : words) {
            ++counts[word[0] - firstLetter][word[1] - firstLetter];
        }
        
        // Iterate through all possible words. Check if they have pairs
        // If they do, add min count of pairs to the result
        int result = 0;
        bool center_piece = false;
        for (int idx = 0; idx < alphabetSize; ++idx) {
            result += (counts[idx][idx] >> 1) << 1;
            // If there's a spare double, use it as center piece
            if (counts[idx][idx] & 1) {
                center_piece = true;
            }
            
            for (int jdx = idx + 1; jdx < alphabetSize; ++jdx) {
                result += std::min(counts[idx][jdx], counts[jdx][idx]) << 1;
            }
        }
        result += center_piece;
        
        return result << 1;
    };
};

// #bugs = 3;

// aa 3
// bb 3
// cc 3
// dd 5