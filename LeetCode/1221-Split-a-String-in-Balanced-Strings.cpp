// LeetCode: 1221. Split a String in Balanced Strings
// Created by Victor Rogulenko

#include <string>
#include <cassert>

int balancedStringSplit(std::string s) {
    int result = 0;
    int balance = 0;
    for (auto& ch : s) {
        if (ch == 'L') {
            ++balance;
        } else {
            --balance;
        }
        if (balance == 0) {
            ++result;
        }
    }
    return result;
}

void RunTestCases() {
    assert(balancedStringSplit("RLRRLLRLRL") == 4);
    assert(balancedStringSplit("RLLLLRRRLR") == 3);
    assert(balancedStringSplit("LLLLRRRR") == 1);
    assert(balancedStringSplit("LR") == 1);
    assert(balancedStringSplit("LLLRLLRRRR") == 1);
}

int main() {
    RunTestCases();
    return 0;
}