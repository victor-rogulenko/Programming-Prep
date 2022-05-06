// LeetCode: 1961. Check If String Is a Prefix of Array
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <vector>

bool isPrefixString(std::string s, const std::vector<std::string>& words) {
    for (auto& word : words) {
        if (s.empty()) {
            return true;
        }
        // if word is not a prefix of s
        if (s.find(word) != 0) {
            return false;
        }
        s.erase(0, word.size());
    }
    return (s.empty());    
}

// 1 <= words.length <= 100
// 1 <= words[i].length <= 20
// 1 <= s.length <= 1000
// words[i] and s consist of only lowercase English letters.

void RunTestCases() {
    std::vector<std::string> words = {"i","love","leetcode","apples"};
    assert(isPrefixString("iloveleetcode", words) == true);
    
    words = {"apples","i","love","leetcode"};
    assert(isPrefixString("iloveleetcode", words) == false);

    words = {"a"};
    assert(isPrefixString("aa", words) == false);

    words = {"a","aa","aaa","aaaa"};
    assert(isPrefixString("aa", words) == false);

    words = {"a","aa","aaa","aaaa"};
    assert(isPrefixString("b", words) == false);

    words = {"a","a","a"};
    assert(isPrefixString("aaa", words) == true);
}

int main() {
    RunTestCases();
    return 0;
}