// LeetCode: 820. Short Encoding of Words
// 820-Short-Encoding-of-Words.cpp
// Created by Victor Rogulenko
// [2022-06-20 23:15]

// A valid encoding of an array of words is any reference string s and array of 
// indices indices such that:
// words.length == indices.length
// The reference string s ends with the '#' character.
// For each index indices[i], the substring of s starting from indices[i] and up 
// to (but not including) the next '#' character is equal to words[i].
// Given an array of words, return the length of the shortest reference string s 
// possible of any valid encoding of words.

// 1 <= words.length <= 2000
// 1 <= words[i].length <= 7
// words[i] consists of only lowercase letters.

// MAJOR IDEA: 1) Reverse all words and sort them. The iterate through the words. 
// If prev word is not the prefix of the current word, update result
// 2) Build a trie on reversed words. Length of all (paths to the leaves + 1) 
// is the answer.

#include <string>
#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
        // reverse the strings
        for (auto& word : words) {
            word = std::string(word.rbegin(), word.rend());
        }
        
        // sort the strings
        std::sort(words.begin(), words.end());
        
        // iterate through the strings and calc result
        int result = 0;
        std::string prev = "#";
        int candidate = -1;
        
        for (auto& word : words) {
            if (word.find(prev) != 0) {
                result += candidate + 1;
            }
            candidate = word.length();
            prev = word;
        }
        result += candidate + 1;
        
        return result;
    }
};