// LeetCode: 1967. Number of Strings That Appear as Substrings in Word
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>
#include <string>

int numOfStrings(const std::vector<std::string>& patterns, std::string word) {
    int result = 0;
    for (auto& elm : patterns) {
        if (word.find(elm) != std::string::npos) {
            ++result;
        }
    }   
    return result; 
}

// 1 <= patterns.length <= 100
// 1 <= patterns[i].length <= 100
// 1 <= word.length <= 100
// patterns[i] and word consist of lowercase English letters.

void RunTestCases() {
    std::vector<std::string> patterns{"a","abc","bc","d"};
    assert(numOfStrings(patterns, "abc") == 3);

    patterns = {"a","b","c"};
    assert(numOfStrings(patterns, "aaaaabbbbb") == 2);

    patterns = {"a","a","a"};
    assert(numOfStrings(patterns, "ab") == 3);

    patterns = {"a"};
    assert(numOfStrings(patterns, "a") == 1);

    patterns = {"a"};
    assert(numOfStrings(patterns, "z") == 0);
}

int main() {
    RunTestCases();
    return 0;
}