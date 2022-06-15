// LeetCode: 1048. Longest String Chain
// 1048-Longest-String-Chain.cpp
// Created by Victor Rogulenko
// [2022-06-15 10:39]	

// You are given an array of words where each word consists of lowercase 
// English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly 
// one letter anywhere in wordA without changing the order of the other 
// characters to make it equal to wordB.
// For example, "abc" is a predecessor of "abac", while "cba" is not a 
// predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, 
// where word1 is a predecessor of word2, word2 is a predecessor of word3, 
// and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen 
// from the given list of words.
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

// MAJOR IDEA: 1) DFS: build a graph and dfs. O(N^2 * word_length)
// 2) DP. Sort words by length. Find dp[idx] = max length for word chains up to idx
// To save time, keep track of first and last indeces of words of a given length
// O(N*word_length^2)

// SOLUTION 1. DFS

#include <vector>
#include <string>
#include <algorithm> // std::max

class Solution {
public:
    bool isPredecessor(const std::string& prev, const std::string& cur) {
        if (prev.size() + 1 != cur.size()) {
            return false;
        }
        
        int cur_size = cur.size();
        int prev_size = prev.size();
        
        int idx = 0, jdx = 0;
        while (idx < cur_size && jdx < prev_size && cur[idx] == prev[jdx]) {
            ++idx;
            ++jdx;
        }
        ++idx;
        while (idx < cur_size && jdx < prev_size && cur[idx] == prev[jdx]) {
            ++idx;
            ++jdx;
        }
        
        return (idx == cur_size && jdx == prev_size);
    }
    
    int dfs(int idx) {
        if (visited[idx]) {
            return maxlen[idx];
        }
        
        visited[idx] = true;
        int num_adj = adjacent[idx].size();
        for (int jdx = 0; jdx < num_adj; ++jdx) {
            maxlen[idx] = std::max(maxlen[idx], 
                                   dfs(adjacent[idx][jdx]) + 1);
        }
        
        return maxlen[idx];
    }
    
    int longestStrChain(const std::vector<std::string>& words) {
        int size = words.size();
        
        // Build a directional graph based on predecessors
        adjacent = std::vector<std::vector<int>>(size);
        
        for (int idx = 0; idx < size; ++idx) {
            for (int jdx = 0; jdx < size; ++jdx) {
                if (idx != jdx && isPredecessor(words[idx], words[jdx])) {
                    adjacent[idx].push_back(jdx);
                } 
            }
        }
        
        // Run dfs to find the longest word chain
        visited = std::vector<bool>(size, false);
        maxlen = std::vector<int>(size, 1);
        int result = 1;
        for (int idx = 0; idx < size; ++idx) {
            if (!visited[idx]) {
                result = std::max(result, dfs(idx));
            }
        }
        
        return result;
    }
    
private:
    std::vector<std::vector<int>> adjacent;
    std::vector<int> maxlen;
    std::vector<bool> visited;
};

// #bugs = 1

// adjacent
// 0: 3
// 1: 
// 2: 0
// 3: 4
// 4: 1

// SOLUTION 2.

bool smallerLength (const std::string& lhs, const std::string& rhs) {
    return lhs.length() < rhs.length();
}

class Solution2 {
public:
    bool isPredecessor(const std::string& prev, const std::string& cur) {
        if (prev.size() + 1 != cur.size()) {
            return false;
        }
        int skip = 0;
        for (int idx = 0; idx < prev.size(); ++idx) {
            if (prev[idx] != cur[idx + skip]) {
                if (skip) {
                    return false;
                }
                ++skip;
                --idx; // Look at the same idx again
            }    
        }
        return true;
    }
    
    int longestStrChain(std::vector<std::string>& words) {
        int words_size = words.size();
        std::sort(words.begin(), words.end(), smallerLength);
        // Store the leftmost and the rightmost indeces of words
        // with a given length;
        std::vector<std::pair<int, int>> cur_length_range(
            words.back().size() +1, {0, -1});
        int leftmost = 0, rightmost;
        for (int idx = 1; idx < words_size; ++idx) {
            if (words[idx-1].length() != words[idx].length()) {
                cur_length_range[words[idx-1].length()] = 
                    {leftmost, idx - 1};
                leftmost = idx;
            }
        }
        cur_length_range[words.back().size()] = 
            {leftmost, words_size - 1};
        
        // Find max length for all words up to idx
        // For each idx, iterate only through words of 
        // length words[idx].length() - 1
        int result = 1;
        std::vector<int> dp(words_size, 1);
        for (int idx = 1; idx < words_size; ++idx) {
            leftmost = cur_length_range[words[idx].length() - 1].first;
            rightmost = cur_length_range[words[idx].length() - 1].second;
            for (int jdx = leftmost; jdx <= rightmost; ++jdx) {
                if (isPredecessor(words[jdx], words[idx])) {
                    dp[idx] = std::max(dp[idx], dp[jdx] + 1);
                }
            result = std::max(result, dp[idx]);
            }
        }
        
        return result;
    }
};