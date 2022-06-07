// LeetCode: 472. Concatenated Words
// 472-Concatenated-Words.cpp
// Created by Victor Rogulenko
// [2022-06-07 12:37]	

// Given an array of strings words (without duplicates), return all the 
// concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of 
// at least two shorter words in the given array.

// 1 <= words.length <= 10^4
// 0 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// 0 <= sum(words[i].length) <= 10^5

// MAJOR IDEA: 1) Build a Trie. Attempt split at each final node. 
// If successful, return split count
// 2) Sort words. Run dfs in every word, trying to split at every index and 
// keeping track of the seen words in an unordered set

#include <vector>
#include <string>

class Solution {
    struct Node {
        std::vector<Node*> next = std::vector<Node*>(26, nullptr);
        bool isFinal = false;
    };
    
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(
        const std::vector<std::string>& words) {
        for (const auto& word : words) {
            addWordToTree(word);
        };
        std::vector<std::string> result;
        for (const auto& word : words) {
            if (cntConcatenated(word, 0) > 1) {
                result.push_back(word);
            }
        };
        return result;
    };
    
private:
    Node* head = new Node();
    
    void addWordToTree (const std::string& word) {
        Node* cur_node = head;
        for (auto ch : word) {
            if (!cur_node->next[ch - 'a']) {
                cur_node->next[ch - 'a'] = new Node();
            }
            cur_node = cur_node->next[ch - 'a'];
        }
        cur_node->isFinal = true;
    };
    
    int cntConcatenated(const std::string& word, int start_idx) {
        if (start_idx >= word.length()) {
            return 0;
        }
        Node* cur_node = head;
        for (int idx = start_idx; idx < word.length(); ++idx) {
            if (!cur_node->next[word[idx] - 'a']) {
                return -1;
            }
            cur_node = cur_node->next[word[idx] - 'a'];
            if (cur_node->isFinal) {
                int try_splitting = cntConcatenated(word, idx+1);
                if (try_splitting >= 0) {
                    return ++try_splitting;
                }
            }
        }
        return -1;
    }    
};

// #bugs = 3