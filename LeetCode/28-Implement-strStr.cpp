// LeetCode: 28. Implement strStr()
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <string>

int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) {
        return 0;
    }
    int res = haystack.find(needle);
    if (res == std::string::npos) {
        res = -1;
    }
    return res;
}

// 1 <= haystack.length, needle.length <= 10^4
// haystack and needle consist of only lowercase English characters.

void RunTestCases() {
    assert(strStr("hello", "ll") == 2);
    assert(strStr("aaaaa", "bba") == -1);
    assert(strStr("aaaaa", "") == 0);
    assert(strStr("a", "aa") == -1);
}

int main() {
    RunTestCases();
    return 0;
}
