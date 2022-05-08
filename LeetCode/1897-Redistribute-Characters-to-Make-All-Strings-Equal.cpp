// LeetCode: 1897. Redistribute Characters to Make All Strings Equal
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>
#include <string>

const int AlphabetSize = 26;

int chInt (char ch) {
    return (int)(ch) - (int)('a');
}

bool makeEqual(std::vector<std::string>& words) {
    std::vector<int> letters_ctr(AlphabetSize, 0);
    for (auto& word : words) {
        for (auto& ch : word) {
            ++letters_ctr[chInt(ch)];
        }
    }
    for (auto& ctr : letters_ctr) {
        if (ctr % words.size() != 0) {
            return false;
        }
    }
    return true;    
}

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

void RunTestCases() {
    std::vector<std::string> words{"abc","aabc","bc"};
    assert(makeEqual(words) == true);

    words = {"ab","a"};
    assert(makeEqual(words) == false);

    words = {"a"};
    assert(makeEqual(words) == true);

    words = {"a", "a"};
    assert(makeEqual(words) == true);

    words = {"a", "b"};
    assert(makeEqual(words) == false);
}

int main() {
    RunTestCases();
    return 0;
}