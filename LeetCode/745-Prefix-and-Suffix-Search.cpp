// LeetCode: 745. Prefix and Suffix Search
// 745-Prefix-and-Suffix-Search.cpp
// Created by Victor Rogulenko
// [2022-06-18 23:06]	

// Design a special dictionary with some words that searchs the words in 
// it by a prefix and a suffix.
// Implement the WordFilter class:
// WordFilter(string[] words) Initializes the object with the words in the dictionary.
// f(string prefix, string suffix) Returns the index of the word in the dictionary, 
// which has the prefix prefix and the suffix suffix. If there is more than one valid 
// index, return the largest of them. If there is no such word in the 
// dictionary, return -1.

// 1 <= words.length <= 15000
// 1 <= words[i].length <= 10
// 1 <= prefix.length, suffix.length <= 10
// words[i], prefix and suffix consist of lower-case English letters only.
// At most 15000 calls will be made to the function f.

// MAJOR IDEA 1. Hash largest indeces for all possible prefix + '_' + suffix combos, 
// then look up quickly
// MAJOR IDEA 2. Trie: suffix#fullword

#include <vector>
#include <string>

class WordFilter {
public:
    WordFilter(std::vector<std::string>& words) {
        // Pre-compute a dictionary
        int words_size = words.size();
        for (int cur_index = 0; cur_index < words_size; ++cur_index) {
            int word_len = words[cur_index].length();
            std::string prefix;
            for (int idx = 0; idx < word_len; ++idx) {
                prefix += words[cur_index][idx];
                std::string dict_key = prefix + '_';
                for (int jdx = 0; jdx < word_len; ++jdx) {
                    dict_key += words[cur_index][word_len - 1 - jdx];
                    auto match = dict.find(dict_key);
                    if (match == dict.end() ||
                        (*match).second < cur_index) {
                        dict[dict_key] = cur_index;
                    }
                }
            }
        }
    }
    
    int f(const std::string& prefix, 
          const std::string& suffix) {
        std::string dict_key = prefix + '_' + 
            std::string(suffix.rbegin(),suffix.rend());
        auto match = dict.find(dict_key);
        if (match != dict.end()) {
            return (*match).second;
        } else {
            return -1;
        }
    }
    
private:
    std::unordered_map<std::string, int> dict;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

// #bugs = 1