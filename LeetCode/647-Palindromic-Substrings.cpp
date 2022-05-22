// LeetCode: 647. Palindromic Substrings
// 647-Palindromic-Substrings.cpp
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

// MAJOR IDEA: Iterate over all possible positions for the middle of 
// the palindrome substring

#include <string>

class Solution {
public:
    int countSubstringsWithAFixedMiddle(const std::string& s, int start, int finish) {
        int result = 0;
        while (start >= 0 && finish < s.size() && s[start] == s[finish]) {
            ++result;
            --start;
            ++finish;
        }
        return result;
    }
    
    int countSubstrings(const std::string& s) {
        int result = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            result += countSubstringsWithAFixedMiddle(s, idx, idx);
            result += countSubstringsWithAFixedMiddle(s, idx, idx + 1);
        }
        return result;
    }
};