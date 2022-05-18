// LeetCode: 211. Design Add and Search Words Data Structure
// 211-Design-Add-and-Search-Words-Data-Structure.cpp
// Created by Victor Rogulenko
// [2022-05-18 13:20]	

// Design a data structure that supports adding new words and finding 
// if a string matches any previously added string.
// Implement the WordDictionary class:
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure 
// that matches word or false otherwise. word may contain dots '.' where dots 
// can be matched with any letter.

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 3 dots in word for search queries.
// At most 10^4 calls will be made to addWord and search.

#include <vector>
#include <string>

class WordDictionary {
    struct Node {
        Node(bool fl) : isFinal(fl) {};
        bool isFinal;
        std::vector<Node*> children = std::vector<Node*>(26, nullptr);
    };
    
public:
    WordDictionary() {
        root_ = new Node(false);
    }
    
    int chToInt(char ch) {
        if (ch == '.') {
            return -1;
        } else {
            return (int)(ch) - (int)('a');
        }
    }
    
    void addWord(std::string word) {
        Node* node = root_;
        
        for (const auto& ch : word) {
            int ch_int = chToInt(ch);
            
            if (!node->children[ch_int]) {
                Node* child = new Node(false);
                node->children[ch_int] = child;
            } 
            node = node->children[ch_int];
        }
        node->isFinal = true;
    }
    
    bool dfs(const std::string& word, int idx, Node* node) {
        if (!node) {
            return false;
        }
        if (idx == word.size()) {
            return node->isFinal;
        }
        
        int cur = chToInt(word[idx]);
        
        if (cur != -1) {
            return dfs(word, idx + 1, node->children[cur]);
        } else {
            for (auto& new_node : node->children) {
                if (dfs(word, idx + 1, new_node)) {
                    return true;
                }
            }
            return false;
        }
    }
    
    bool search(std::string word) {
        return dfs(word, 0, root_);
    }
    
private:
    Node* root_ = nullptr;
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */