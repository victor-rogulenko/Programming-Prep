// LeetCode: 1647. Minimum Deletions to Make Character Frequencies Unique
// 1647-Minimum-Deletions-to-Make-Character-Frequencies-Unique.cpp
// Created by Victor Rogulenko
// [2022-06-28 23:44]

// A string s is called good if there are no two different characters 
// in s that have the same frequency.
// Given a string s, return the minimum number of characters you need 
// to delete to make s good.
// The frequency of a character in a string is the number of times it 
// appears in the string. For example, in the string "aab", the frequency 
// of 'a' is 2, while the frequency of 'b' is 1.

// 1 <= s.length <= 10^5
// s contains only lowercase English letters.

// MAJOR IDEA: Build and sort an array of char counts. Iterate from biggest counts
// to smallest. Decrease each count so that it becomes smaller than the previous count.

#include <string>
#include <algorithm> // std::sort

class Solution {
public:
    int minDeletions(const std::string& s) {
        // Convert s into a map "letter - count"
        int charCount[26] = {0};
        for (auto ch : s) {
            ++charCount[(int)(ch) - (int)('a')];
        }
        
        // Sort the count
        std::sort(charCount, charCount + 26);
        
        // Iterate from largest to smallest change values
        // so that no value is repeated (except for 0)
        int result = 0;
        for (int idx = 24; idx >= 0; --idx) {
            if (charCount[idx] >= charCount[idx + 1] && 
                charCount[idx] != 0) {
                
                result += charCount[idx] - charCount[idx + 1] + 
                    1 * (charCount[idx + 1] > 0);
                charCount[idx] = charCount[idx + 1] - 
                    1 * (charCount[idx + 1] > 0);
            }
        }
        
        return result;
    }
};

// #bugs = 2

// "abcabc"
// 2 2 2
// 0 1 2

// "bbcebab"
// 1 1 1 4