// LeetCode: 2138. Divide a String Into Groups of Size k
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <vector>

std::vector<std::string> divideString(std::string s, int k, char fill) {
    std::vector<std::string> result;
    int idx = 0;
    while (idx < s.length()) {
        result.push_back(s.substr(idx, k));
        idx += k;
    }
    if ((result.size() > 0) && (result.back().length() < k)) {
        int len = result.back().length();
        result.back().insert(len, k-len, fill);
    }
    return result;
}

// 1 <= s.length <= 100
// s consists of lowercase English letters only.
// 1 <= k <= 100
// fill is a lowercase English letter.

void RunTestCases() {
    assert((divideString("abcdefghi", 3, 'x') == std::vector<std::string>{"abc","def","ghi"}));
    assert((divideString("abcdefghij", 3, 'x') == std::vector<std::string>{"abc","def","ghi", "jxx"}));
    assert((divideString("abc", 1, 'x') == std::vector<std::string>{"a","b","c"}));
    assert((divideString("a", 1, 'x') == std::vector<std::string>{"a"}));
    assert((divideString("a", 5, 'x') == std::vector<std::string>{"axxxx"}));
}

int main() {
    RunTestCases();
    return 0;
}