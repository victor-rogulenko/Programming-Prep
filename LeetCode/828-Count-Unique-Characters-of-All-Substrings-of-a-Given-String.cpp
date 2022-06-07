// LeetCode: 828. Count Unique Characters of All Substrings of a Given String
// 828-Count-Unique-Characters-of-All-Substrings-of-a-Given-String.cpp
// Created by Victor Rogulenko
// [2022-06-07 14:06]	

// Let's define a function countUniqueChars(s) that returns the number of unique 
// characters on s.
// For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", 
// "O", "D" are the unique characters since they appear only once in s, therefore 
// countUniqueChars(s) = 5.
// Given a string s, return the sum of countUniqueChars(t) where t is a substring 
// of s.
// Notice that some substrings can be repeated so in this case you have to count 
// the repeated ones too.

// 1 <= s.length <= 10^5
// s consists of uppercase English letters only.

// MAJOR IDEA: For each char 'A' .. 'Z', count # substrings where this char is unique
// To do that, keep track of the last 3 positions for each char and update
// result += (pos_1 - pos_2) * (post_cur - pos_1)

#include <string>
#include <cstring> // std::memset

class Solution {
public:
    int uniqueLetterString(const std::string& s) {
        int charPositions[26][2];
        std::memset(charPositions, -1, sizeof(int) * 52);
        int result = 0, len = s.length();
        for (int posCur = 0; posCur < len; ++posCur) {
            int ch = s[posCur] - 'A';
            int posMinus2 = charPositions[ch][0];
            int posMinus1 = charPositions[ch][1];
            result += (posMinus1 - posMinus2) * (posCur - posMinus1);
            charPositions[ch][0] = posMinus1;
            charPositions[ch][1] = posCur;
        }        
        for (int idx = 0; idx < 26; ++idx) {
            int posMinus2 = charPositions[idx][0];
            int posMinus1 = charPositions[idx][1];
            int posCur = len;
            result += (posCur - posMinus1) * (posMinus1 - posMinus2);
        }
        return result;
    }
};

// #bugs = 1

// A: -1, 0, 3 -> 3
// B: -1, 1, 3 -> 4
// C: -1, 2, 3 -> 3