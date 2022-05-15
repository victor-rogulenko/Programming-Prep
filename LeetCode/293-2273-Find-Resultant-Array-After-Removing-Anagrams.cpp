// LeetCode: 2273. Find Resultant Array After Removing Anagrams
// 293-2273-Find-Resultant-Array-After-Removing-Anagrams.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// You are given a 0-indexed string array words, where words[i] consists 
// of lowercase English letters.
// In one operation, select any index i such that 0 < i < words.length and 
// words[i - 1] and words[i] are anagrams, and delete words[i] from words. 
// Keep performing this operation as long as you can select an index that 
// satisfies the conditions.
// Return words after performing all operations. It can be shown that 
// selecting the indices for each operation in any arbitrary order will 
// lead to the same result.
// An Anagram is a word or phrase formed by rearranging the letters of a 
// different word or phrase using all the original letters exactly once. 
// For example, "dacb" is an anagram of "abdc".

// 1 <= words.length <= 100
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {};

    vector<string> removeAnagrams(vector<string>& words) {
        bool flag = true;
        vector<int> indices(words.size(), 0);
        for (int idx = 0; idx < indices.size(); ++idx) {
            indices[idx] = idx;
        }
        vector<string> words2 = words;
        for (auto& str : words2) {
            sort(str.begin(), str.end());
        }

        int idx = 0;
        while (idx + 1 < indices.size()) {
            flag = false;
            if (words2[indices[idx]] == words2[indices[idx+1]]) {
                flag = true;
                indices.erase(indices.begin()+idx+1);
            }
            if (!flag) ++idx;
        }
        
        vector<string> result;
        for (int idx = 0; idx < indices.size(); ++idx) {
            result.push_back(words[indices[idx]]);
        }
        return result;
    }
};

void TestCase(vector<string> input, vector<string> expected) {
    vector<string> result = Solution().removeAnagrams(input);
    // std::cout << "result = " << result << ", expected = " << expected << "\n";
    for (auto word : result) {
        std::cout << word << "\n";
    }
    assert(result == expected);
}

void RunTestCases() {
    TestCase({"abba","baba","bbaa","cd","cd"}, {"abba","cd"});
    TestCase({"z","z","z","gsw","wsg","gsw","krptu"}, {"z","gsw","krptu"});
}

int main() {
    RunTestCases();
    return 0;
}