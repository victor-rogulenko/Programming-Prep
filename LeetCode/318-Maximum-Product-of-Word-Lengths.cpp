// LeetCode: 318. Maximum Product of Word Lengths
// 318-Maximum-Product-of-Word-Lengths.cpp
// Created by Victor Rogulenko
// [2022-05-29 22:46]	

// Given a string array words, return the maximum value of 
// length(word[i]) * length(word[j]) where the two words do not 
// share common letters. If no such two words exist, return 0.

// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists only of lowercase English letters.

// MAJOR IDEA: Transform words into binary, 
// i-th bit = 1 is i-th letter of the alphabet is present in this word. 
// Then AND words to find pairs without repeating letters

#include <vector>
#include <string>

const int alphabetSize = 26;

class Solution {
public:
    int countLettersInWord(const std::string& word) {
        int cnt[alphabetSize];
        
        for (int idx = 0; idx < alphabetSize; ++idx) {
            cnt[idx] = 0;
        }
        
        for (const auto ch : word) {
            ++cnt[(int)(ch) - (int)('a')];
        }
        
        int result = 0;
        for (int idx = 0; idx < alphabetSize; ++idx) {
            result += (1 << idx) * (cnt[idx] > 0);
        }
        
        return result;
    }
    
    int maxProduct(const std::vector<std::string>& words) {
        int num_words = words.size();
        int* letters_cnt = new int[num_words];
        
        for (int idx = 0; idx < words.size(); ++idx) {
            letters_cnt[idx] = countLettersInWord(words[idx]);
        }
        
        int result = 0;
        
        for (int idx = 0; idx < words.size(); ++idx) {
            for (int jdx = idx + 1; jdx < words.size(); ++jdx) {
                if ((letters_cnt[idx] & letters_cnt[jdx]) == 0) {
                    int candidate = words[idx].size() * words[jdx].size();
                    result = std::max(result, candidate);
                }
            }
        }
        
        delete []letters_cnt;
        return result;
    }
};

// #bugs = 4