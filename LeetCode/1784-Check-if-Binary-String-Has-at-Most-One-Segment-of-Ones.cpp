// LeetCode: 1784. Check if Binary String Has at Most One Segment of Ones
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>

bool checkOnesSegment(std::string s) {
    int idx = 0;
    while ((idx < s.length()) && (s[idx] == '1')) {
        ++idx;
    }
    while ((idx < s.length()) && (s[idx] == '0')) {
        ++idx;
    }
    return (idx == s.length());
}

// 1 <= s.length <= 100
// s[i]​​​​ is either '0' or '1'.
// s[0] is '1'.

void RunTestCases() {
    assert(checkOnesSegment("1001") == false);
    assert(checkOnesSegment("110") == true);
    assert(checkOnesSegment("1") == true);
    assert(checkOnesSegment("10") == true);
    assert(checkOnesSegment("11111111110") == true);
    assert(checkOnesSegment("111111111101") == false);
    assert(checkOnesSegment("1111111111") == true);
}

int main() {
    RunTestCases();
    return 0;
}