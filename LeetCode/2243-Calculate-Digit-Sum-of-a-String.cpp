// LeetCode: 2243. Calculate Digit Sum of a String
// Created by Victor Rogulenko
// May 6, 2022

#include <cassert>
#include <string>

std::string completeOneRound(const std::string& s, int k) {
    std::string result = "";
    int current_sum = 0;
    int current_len = 0;
    for (auto& ch : s) {
        int current_int = (int)(ch) - (int)('0');
        current_sum += current_int;
        ++current_len;
        if (current_len == k) {
            current_len = 0;
            result += std::to_string(current_sum);
            current_sum = 0;
        }
    }
    if (current_len > 0) {
        result += std::to_string(current_sum);
    }
    return result;
}

std::string digitSum(std::string s, int k) {
    while (s.length() > k) {
        s = completeOneRound(s, k);
    }
    return s;    
}

// 1 <= s.length <= 100
// 2 <= k <= 100
// s consists of digits only.

void RunTestCases() {
    assert(digitSum("11111222223", 3) == "135");
    assert(digitSum("00000000", 3) == "000");
    assert(digitSum("1", 2) == "1");
    assert(digitSum("100", 2) == "10");
}

int main() {
    RunTestCases();
    return 0;
}