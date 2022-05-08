// LeetCode: 1768. Merge Strings Alternately
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <string>

std::string mergeAlternately(std::string word1, std::string word2) {
    std::string result = "";
    for (int idx = 0; ((idx < word1.length()) && (idx < word2.length())); ++idx) {
        result += word1[idx]; 
        result += word2[idx];
    }
    if (word1.length() > word2.length()) {
        result += word1.substr(word2.length());
    } else {
        result += word2.substr(word1.length());
    }       
    return result;
}

void RunTestCases() {
    assert(mergeAlternately("abc", "pqr") == "apbqcr");
    assert(mergeAlternately("ab", "pqrs") == "apbqrs");
    assert(mergeAlternately("abcd", "pq") == "apbqcd");
    assert(mergeAlternately("a", "a") == "aa");
}

int main() {
    RunTestCases();
    return 0;
}