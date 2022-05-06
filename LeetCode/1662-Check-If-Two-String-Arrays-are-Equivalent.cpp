// LeetCode: 1662. Check If Two String Arrays are Equivalent
// Created by Victor Rogulenko
// May 6, 2022

#include <cassert>
#include <string>
#include <vector>

std::string vectorToString(const std::vector<std::string>& word1) {
    std::string result = "";
    for (auto& elm : word1) {
        result += elm;
    }
    return result;
}

bool arrayStringsAreEqual(const std::vector<std::string>& word1, 
                          const std::vector<std::string>& word2) {
    std::string string1 = vectorToString(word1);
    std::string string2 = vectorToString(word2);
    return (string1 == string2);    
}

// 1 <= word1.length, word2.length <= 10^3
// 1 <= word1[i].length, word2[i].length <= 10^3
// 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
// word1[i] and word2[i] consist of lowercase letters.

void RunTestCases() {
    std::vector<std::string> word1 = {"ab", "c"};
    std::vector<std::string> word2 = {"a", "bc"};
    assert(arrayStringsAreEqual(word1, word2) == true);

    word1 = {"a", "cb"};
    word2 = {"ab", "c"};
    assert(arrayStringsAreEqual(word1, word2) == false);

    word1 = {"abc", "d", "defg"};
    word2 = {"abcddefg"};
    assert(arrayStringsAreEqual(word1, word2) == true);

    word1 = {"a"};
    word2 = {"b"};
    assert(arrayStringsAreEqual(word1, word2) == false);

    word1 = {"a"};
    word2 = {"a"};
    assert(arrayStringsAreEqual(word1, word2) == true);
}

int main() {
    RunTestCases();
    return 0;
}