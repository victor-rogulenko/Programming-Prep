// LeetCode: 1903. Largest Odd Number in String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

std::string largestOddNumber(const std::string& num) {
    int idx = num.length() - 1;
    while (idx >= 0) {
        if (((int)(num[idx]) - (int)('0')) % 2 == 0) {
            --idx;
        } else {
            break;
        }
    }
    return num.substr(0, idx+1);
}

void RunTestCases() {
    assert(largestOddNumber("52") == "5");
    assert(largestOddNumber("4206") == "");
    assert(largestOddNumber("35427") == "35427");
    assert(largestOddNumber("2") == "");
    assert(largestOddNumber("1000000000000000000000000000000000000000") == "1");
}

int main() {
    RunTestCases();
    return 0;
}