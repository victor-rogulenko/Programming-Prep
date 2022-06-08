// LeetCode: 1268. Search Suggestions System
// 1268-Search-Suggestions-System.cpp
// Created by Victor Rogulenko
// [2022-06-08 15:17]	

// You are given an array of strings products and a string searchWord.
// Design a system that suggests at most three product names from products 
// after each character of searchWord is typed. Suggested products should have 
// common prefix with searchWord. If there are more than three products with a 
// common prefix return the three lexicographically minimums products.
// Return a list of lists of the suggested products after each character of 
// searchWord is typed.

// 1 <= products.length <= 1000
// 1 <= products[i].length <= 3000
// 1 <= sum(products[i].length) <= 2 * 10^4
// All the strings of products are unique.
// products[i] consists of lowercase English letters.
// 1 <= searchWord.length <= 1000
// searchWord consists of lowercase English letters.

// MAJOR IDEA: 1) Trie: build a trie, move head with each character of
// seachWord and pre-order traversal to find 3 matching words
// 2) Sorting and 2 pointers: sort products, then use pointers start and finish
// pointing at the interval matching the prefix of searchWord. Take the first
// 3 words from this intervals. ++start and --finish to match the next character
// of searchWord

// SOLUTION 1. Trie

#include <vector>
#include <string>

struct Node {
    bool isFinal = false;
    std::vector<Node*> next = std::vector<Node*>(26, nullptr);
};

class Solution {
    const int MaxMatches = 3;
public:
    std::vector<std::vector<std::string>> suggestedProducts(
        const std::vector<std::string>& products, const std::string& searchWord) {
        head = buildTrie(products);
        Node* cur_node = head;
        bool possible_moves = true;
        std::string prefix = "";
        for (const auto& ch : searchWord) {
            if (!possible_moves || !cur_node->next[ch-'a']) {
                possible_moves = false;
                result.push_back({});
                continue;
            }
            prefix += ch;
            cur_node = cur_node->next[ch-'a']; 
            candidate.clear();
            findMatches(cur_node, prefix, "");
            result.push_back(candidate);
        }
        return result;
    }
    
private:
    Node* head = nullptr;
    std::vector<std::string> candidate;
    std::vector<std::vector<std::string>> result;
    
    Node* buildTrie(const std::vector<std::string>& products) {
        Node* head = new Node();
        for (const auto& product : products) {
            Node* cur_node = head;
            for (const auto& ch : product) {
                if (!cur_node->next[ch-'a']) {
                    cur_node->next[ch-'a'] = new Node();
                }
                cur_node = cur_node->next[ch-'a'];
            }
            cur_node->isFinal = true;
        }
        return head;
    };
    
    void findMatches(Node* cur_node, const std::string& prefix,
                     std::string word_candidate) {
        if (candidate.size() >= MaxMatches) {
            return;
        }
        if (cur_node->isFinal) {
            candidate.push_back(prefix + word_candidate);
        }
        for (int idx = 0; idx < 26; ++idx) {
            if (cur_node->next[idx]) {
                findMatches(cur_node->next[idx], prefix, 
                	word_candidate + (char)('a' + idx));
            }
            if (candidate.size() >= MaxMatches) {
                return;
            }
        }
    }
};

// #bugs = 3

// SOLUTION 2. Sorting and 1 pointers

class Solution2 {
    const int MaxMatches = 3;
public:
    std::vector<std::vector<std::string>> suggestedProducts(
        std::vector<std::string>& products, const std::string& searchWord) {
        
        std::vector<std::vector<std::string>> result;
        std::sort(products.begin(), products.end());
        
        int start = 0;
        int finish = products.size()-1;
        
        for (int idx = 0; idx < searchWord.length(); ++idx) {
            while (start <= finish && 
                   (products[start].size() <= idx || 
                    searchWord[idx] != products[start][idx])) {
                ++start;
            }
            while (start <= finish && 
                   (products[finish].size() <= idx ||
                    searchWord[idx] != products[finish][idx])) {
                --finish;           
            }
            std::vector<std::string> candidate;
            for (int jdx = start; jdx <= finish && jdx < start + MaxMatches; ++jdx) {
                candidate.push_back(products[jdx]);
            }
            result.push_back(candidate);
        }
        
        return result;
    }
};