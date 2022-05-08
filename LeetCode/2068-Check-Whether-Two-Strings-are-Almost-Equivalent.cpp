// LeetCode: 2068. Check Whether Two Strings are Almost Equivalent
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <string>
#include <vector>
#include <cmath> // std::abs

const int AlphabetSize = 26;

int chInt(char ch) {
    return (int)(ch) - (int)('a');
}

std::vector<int> buildOccurancesVector(const std::string& word) {
    std::vector<int> result(AlphabetSize, 0);
    for (auto& ch : word) {
        ++result[chInt(ch)];
    }
    return result;
}

bool checkAlmostEquivalent(std::string word1, std::string word2) {
    std::vector<int> library1 = buildOccurancesVector(word1);
    std::vector<int> library2 = buildOccurancesVector(word2);
    for (int idx = 0; idx < AlphabetSize; ++idx) {
        if (std::abs(library1[idx] - library2[idx]) > 3) {
            return false;
        }
    }
    return true;    
}

// n == word1.length == word2.length
// 1 <= n <= 100
// word1 and word2 consist only of lowercase English letters.

void RunTestCases() {
    assert(checkAlmostEquivalent("aaaa", "bccb") == false);
    assert(checkAlmostEquivalent("abcdeef", "abcdeef") == true);
    assert(checkAlmostEquivalent("cccddabba", "babababab") == true);
    assert(checkAlmostEquivalent("a", "a") == true);
    assert(checkAlmostEquivalent("a", "z") == true);
    assert(checkAlmostEquivalent("aaa", "zzz") == true);
}

int main() {
    RunTestCases();
    return 0;
}