// LeetCode: 1758. Minimum Changes To Make Alternating Binary String
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>

int countOperations(const std::string& s, char starting_char) {
    int result = 0;
    char expected_ch = starting_char;
    for (auto& ch : s) {
        result += (ch != expected_ch);
        if (expected_ch == '0') {
            expected_ch = '1';
        } else {
            expected_ch = '0';
        }
    }
    return result;
}

int minOperations(std::string s) {
    int cnt_1 = countOperations(s, '1');
    int cnt_0 = countOperations(s, '0');
    return (cnt_0 < cnt_1 ? cnt_0 : cnt_1);          
}

// 1 <= s.length <= 10^4
// s[i] is either '0' or '1'

void RunTestCases() {
    assert(minOperations("0100") == 1);
    assert(minOperations("10") == 0);
    assert(minOperations("1111") == 2);
    assert(minOperations("1") == 0);
    assert(minOperations("0") == 0);
    assert(minOperations("0101") == 0);
}

int main() {
    RunTestCases();
    return 0;
}