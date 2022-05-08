// LeetCode:  1684. Count the Number of Consistent Strings
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <string>
#include <vector>

const int AlphabetSize = 26;

int chInt(char ch) {
    return (int)(ch) - (int)('a');
}

std::vector<bool> buildAllowedLibrary(const std::string& allowed) {
    std::vector<bool> result(AlphabetSize, false);
    for (auto& ch : allowed) {
        result[chInt(ch)] = true;
    }
    return result;
}

bool isAllowed(const std::vector<bool>& library, const std::string& word) {
    for (auto& ch : word) {
        if (!library[chInt(ch)]) {
            return false;
        }
    }
    return true;
}

int countConsistentStrings(std::string allowed, const std::vector<std::string>& words) {
    std::vector<bool> library = buildAllowedLibrary(allowed);
    int result = 0;
    for (auto& word : words) {
        if (isAllowed(library, word)) {
            ++result;
        }
    }                
    return result;
}

// 1 <= words.length <= 10^4
// 1 <= allowed.length <= 26
// 1 <= words[i].length <= 10
// The characters in allowed are distinct.
// words[i] and allowed contain only lowercase English letters.

void RunTestCases() {
    std::vector<std::string> words{"ad","bd","aaab","baa","badab"};
    assert(countConsistentStrings("ab", words) == 2);
   
    words = {"a","b","c","ab","ac","bc","abc"};
    assert(countConsistentStrings("abc", words) == 7);

    words = {"cc","acd","b","ba","bac","bad","ac","d"};
    assert(countConsistentStrings("cad", words) == 4);

    words = {"cc"};
    assert(countConsistentStrings("a", words) == 0);
}

int main() {
    RunTestCases();
    return 0;
}