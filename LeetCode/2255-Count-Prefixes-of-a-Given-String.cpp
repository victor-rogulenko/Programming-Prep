// LeetCode: 2255. Count Prefixes of a Given String
// Created by Victor Rogulenko
// May 6, 2022

#include <cassert>
#include <string>
#include <vector>

int countPrefixes(const std::vector<std::string>& words, std::string s) {
    int result = 0;
    for (auto& word : words) {
        int idx = s.find(word);
        result += (idx == 0);
    }
    return result;        
}

// 1 <= words.length <= 1000
// 1 <= words[i].length, s.length <= 10
// words[i] and s consist of lowercase English letters only.

void RunTestCases() {
    std::vector<std::string> words = {"a","b","c","ab","bc","abc"}; 
    assert(countPrefixes(words, "abc") == 3);

    words = {"a","a"};
    assert(countPrefixes(words, "aa") == 2);
    
    words = {"a"};
    assert(countPrefixes(words, "a") == 1);    

    words = {"b"};
    assert(countPrefixes(words, "a") == 0);

    words = {"a","b","c","ab","bc","abc"}; 
    assert(countPrefixes(words, "zzabc") == 0);    
}

int main() {
    RunTestCases();
    return 0;
}