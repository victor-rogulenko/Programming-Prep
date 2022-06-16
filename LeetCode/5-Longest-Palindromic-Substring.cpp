// LeetCode: 5. Longest Palindromic Substring
// 5-Longest-Palindromic-Substring.cpp
// Created by Victor Rogulenko
// [2022-06-16 23:38]	

// Given a string s, return the longest palindromic substring in s.
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// MAJOR IDEA: Iterate over possible middle letters. Careful with 
// even-length palindromes

#include <string>

class Solution {
public:    
    std::string longestPalindrome(const std::string& s) {
        std::pair<int,int> result = {0, 1};
        int len = s.length();
        
        for (int middle = 0; middle + 1 < len; ++middle) {
            auto candidate = findPalindrome(s, middle, middle + 1);
            updatePair(result, candidate);
            
            candidate = findPalindrome(s, middle - 1, middle + 1);
            updatePair(result, candidate);
        };
        
        return s.substr(result.first, result.second);
    }; 

private:
    std::pair<int,int> findPalindrome(const std::string& s, 
                                      int left, int right) {
        int candidate_length = right - left - 1;
        int len = s.length();
        while (left >= 0 && right < len && s[left] == s[right]) {
            candidate_length += 2;
            --left;
            ++right;
        }
        
        return {left+1, candidate_length};
    }
    
    void updatePair(std::pair<int,int>& result,
                    const std::pair<int, int> candidate) {
        if (result.second < candidate.second) {
            result = candidate;
        }
    }
};

// #bugs = 3