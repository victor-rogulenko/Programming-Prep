// LeetCode: 1309. Decrypt String from Alphabet to Integer Mapping
// Created by Victor Rogulenko
// May 6, 2022

#include <cassert>
#include <string>
#include <stack>

std::stack<int> stringToStack(std::string s) {
    // Build a stack of letter indices ranging from 1 to 26
    std::stack<int> result;
    for (auto& ch : s) {
        if (ch == '#') {
            int second_digit = result.top();
            result.pop();
            int first_digit = result.top();
            result.pop();
            result.push(first_digit * 10 + second_digit);
        } else {
            result.push((int)(ch) - (int)('0'));
        } 
    }
    return result;
}

std::string freqAlphabets(std::string s) {
    std::stack<int> letter_indices = stringToStack(s);
    std::string result = "";
    while (!letter_indices.empty()) {
        result += (char)(letter_indices.top() + (int)('a') - 1);
        letter_indices.pop();
    }
    return (std::string(result.rbegin(), result.rend()));
}

// 1 <= s.length <= 1000
// s consists of digits and the '#' letter.
// s will be a valid string such that mapping is always possible.

void RunTestCases() {
    assert(freqAlphabets("10#11#12") == "jkab");
    assert(freqAlphabets("1326#") == "acz");
    assert(freqAlphabets("1") == "a");
    assert(freqAlphabets("26#") == "z");
}

int main() {
    RunTestCases();
    return 0;
}