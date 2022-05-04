// LeetCode: 1408. String Matching in an Array
// Created by Victor Rogulenko

#include <cassert>
#include <vector>
#include <string>
#include <algorithm> // sort

const size_t AlphabetSize = 26;

struct Node {
    std::vector<Node*> children = std::vector<Node*>(AlphabetSize, nullptr);
};

class Trie {
public:
    Trie() : root(new Node()) {};

    void addString(const std::string& s) {
        Node* node = root;
        for (auto ch : s) {
            int idx = (int)(ch) - (int)('a');
            if (node->children[idx] != nullptr) {
                node = node->children[idx];
            } else {
                Node* temp = new Node();
                node->children[idx] = temp;
                node = temp;    
            } 
        }
    };

    bool isPresentInTrie(const std::string& s) {
        Node* node = root;
        for (auto ch : s) {
            int idx = (int)(ch) - (int)('a');
            if (node->children[idx] != nullptr) {
                node = node->children[idx];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    Node* root;
};

std::vector<std::string> stringMatching(std::vector<std::string>& words) {
    std::vector<std::string> result;
    Trie* trie = new Trie();
    // We need sorting to make sure a word does not match with itself.
    // Feed longer words into the trie first
    std::sort(words.begin(), words.end(), 
        [](const std::string& lhs, const std::string& rhs) {
            return (lhs.size() > rhs.size());
        }
    );
    for (auto& word : words) {
        if (trie->isPresentInTrie(word)) {
            result.push_back(word);
        }
        for (int idx = 0; idx < word.length(); ++idx) {
            trie->addString(word.substr(idx));
        }
    }
    return result;
};

void RunSingleCase(std::vector<std::string> input, std::vector<std::string> expected_output) {
    std::vector<std::string> actual_result = stringMatching(input);
    std::sort(expected_output.begin(), expected_output.end());
    std::sort(actual_result.begin(), actual_result.end());
    assert (actual_result == expected_output);
}

void RunTestCases() {
    RunSingleCase(std::vector<std::string>{"mass","as","hero","superhero"}, std::vector<std::string>{"as","hero"});
    RunSingleCase(std::vector<std::string>{"leetcode","et","code"}, std::vector<std::string>{"et","code"});
    RunSingleCase(std::vector<std::string>{"blue","green","bu"}, std::vector<std::string>{});
    RunSingleCase(std::vector<std::string>{"a"}, std::vector<std::string>{});    
}

int main() {
    RunTestCases();
    return 0;
}