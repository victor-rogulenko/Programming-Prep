// LeetCode: 208-Implement-Trie.cpp
// Created by Victor Rogulenko
// [2022-05-01 17:23]

#include <vector>
#include <iostream>
#include <cassert>
#include <string>

const size_t AlphabetSize = 30;

struct Node {
	bool isTerminal = false;
	std::vector<Node*> children = std::vector<Node*>(AlphabetSize, nullptr);
};

int charToInt(char ch) {
	return (int)ch - (int)'a';
}

class Trie {
public:
    Trie() {}
    
    void insert(const std::string& word) {
    	Node* current = this->root;
    	for (auto& ch : word) {
    		int ch_int = charToInt(ch);
    		if (current->children[ch_int]) {
    			current = current->children[ch_int];
    		} else {
    			Node* new_node = new Node();
    			current->children[ch_int] = new_node;
    			current = new_node;
    		}
    	}
    	current->isTerminal = true;
    }

    Node* findNode(const std::string& word) {
    	Node* current = this->root;
    	for (auto& ch : word) {
    		int ch_int = charToInt(ch);
    		if (current->children[ch_int]) {
    			current = current->children[ch_int];
    		} else {
    			return nullptr;
    		}
    	}
        return current;    	
    }
    
    bool search(const std::string& word) {
    	Node* result = this->findNode(word);
    	return ((result != nullptr) && (result->isTerminal));
    }
    
    bool startsWith(const std::string& prefix) {
    	Node* result = this->findNode(prefix);
    	return (result != nullptr);
    }

private:
	Node* root = new Node();
};

int main() {

	Trie* trie = new Trie();
	trie->insert("app");
	trie->insert("apple");
	assert (trie->search("apple"));
	assert (trie->search("app"));
	return 0;
}