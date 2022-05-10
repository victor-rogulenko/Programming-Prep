// LeetCode: 1614. Maximum Nesting Depth of the Parentheses
// Created by Victor Rogulenko
// May 10, 2022

// Given a valid parenthesis string represented as string s, 
// return the nesting depth of s

// 1 <= s.length <= 100
// s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
// It is guaranteed that parentheses expression s is a VPS.

#include <cassert>
#include <string>

int maxDepth(const std::string& s) {
    int result = 0;
    int ctr = 0;
    for (auto ch : s) {
        if (ch == '(') {
            ++ctr;
        } else if (ch == ')') {
            --ctr;
        }
        result = (result < ctr ? ctr : result);
    }
    return result;
}

void RunTestCases() {
    std::string test = "(1+(2*3)+((8)/4))+1";
    assert(maxDepth(test) == 3);

    test = "(1)+((2))+(((3)))";
    assert(maxDepth(test) == 3);

    test = "";
    assert(maxDepth(test) == 0);

    test = "CAD";
    assert(maxDepth(test) == 0);

    test = "()";
    assert(maxDepth(test) == 1);
}

int main() {
    RunTestCases();
    return 0;
}