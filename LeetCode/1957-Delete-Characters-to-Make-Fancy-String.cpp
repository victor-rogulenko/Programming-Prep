// LeetCode: 1957. Delete Characters to Make Fancy String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

std::string makeFancyString(std::string s) {
    if (s.empty()) {
        return s;
    }
    std::string result = "";
    result += s[0];
    bool last_two_chars_are_the_same = false;
    for (int idx = 1; idx < s.length(); ++idx) {
        if ((result.back() == s[idx]) && (last_two_chars_are_the_same)) {
            continue;
        }
        last_two_chars_are_the_same = (result.back() == s[idx]);
        result += s[idx];
    }
    return result;   
}

void RunTestCases() {
    assert(makeFancyString("leeetcode") == "leetcode");
    assert(makeFancyString("aaabaaaa") == "aabaa");
    assert(makeFancyString("aab") == "aab");
    assert(makeFancyString("a") == "a");
    assert(makeFancyString("aa") == "aa");
    assert(makeFancyString("aaa") == "aa");
    assert(makeFancyString("aaaaaaaaaaaaaa") == "aa");
    assert(makeFancyString("aaccca") == "aacca");
}

int main() {
    RunTestCases();
    return 0;
}