// LeetCode: 833. Find And Replace in String
// 833-Find-And-Replace-in-String.cpp
// Created by Victor Rogulenko
// [2022-08-05 14:47]  

// You are given a 0-indexed string s that you must perform k replacement 
// operations on. The replacement operations are given as three 
// 0-indexed parallel arrays, indices, sources, and targets, all of length k.
// To complete the ith replacement operation:
// - Check if the substring sources[i] occurs at index indices[i] in the 
// original string s.
// - If it does not occur, do nothing.
// - Otherwise if it does occur, replace that substring with targets[i].
// For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and t
// argets[i] = "eee", then the result of this replacement will be "eeecd".
// All replacement operations must occur simultaneously, meaning the replacement 
// operations should not affect the indexing of each other. The testcases will 
// be generated such that the replacements will not overlap.
// For example, a testcase with s = "abc", indices = [0, 1], and 
// sources = ["ab","bc"] will not be generated because the "ab" and "bc" 
// replacements overlap.
// Return the resulting string after performing all replacement operations on s.
// A substring is a contiguous sequence of characters in a string.
// 1 <= s.length <= 1000
// k == indices.length == sources.length == targets.length
// 1 <= k <= 100
// 0 <= indexes[i] < s.length
// 1 <= sources[i].length, targets[i].length <= 50
// s consists of only lowercase English letters.
// sources[i] and targets[i] consist of only lowercase English letters.

// MAJOR IDEA: Store the new string as a vector of strings. Update it 
// with target segments when applicable
// Time: O(N+M). Space: O(N+M), N - length of string, M - total length of
// targets

#include <string>
#include <vector>

class Solution {
public:
    std::string findReplaceString(const std::string& s, 
                                  const std::vector<int>& indices, 
                                  const std::vector<string>& sources, 
                                  const std::vector<string>& targets) {
        std::vector<std::string> stringParts(s.length(), "");
        for (int idx = 0; idx < s.length(); ++idx) {
            stringParts[idx] += s[idx];
        }
        
        // Process operations
        for (int idx = 0; idx < indices.size(); ++idx) {
            int sourceLen = sources[idx].size();
            if (s.substr(indices[idx], sourceLen) == sources[idx]) {
                int jdxEnd = indices[idx] + sourceLen;
                for (int jdx = indices[idx]; jdx < jdxEnd; ++jdx) {
                    stringParts[jdx] = "";
                }
                stringParts[indices[idx]] = targets[idx];
            }
        }
        
        // Assemble the final string
        std::string result;
        for (auto& str : stringParts) {
            result += str;
        }
        return result;
    }
};