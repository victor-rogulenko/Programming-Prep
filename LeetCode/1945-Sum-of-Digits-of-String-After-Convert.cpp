// LeetCode: 1945. Sum of Digits of String After Convert
// Created by Victor Rogulenko

#include <string>
#include <cassert>

int SumUpDigitsInInteger(int num) {
    int result = 0;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int ConvertCharsAndSumUpDigits(const std::string& s) {
    int result = 0;
    for (auto& ch : s) {
        int ch_int = (int)(ch) - (int)('a') + 1;
        result += SumUpDigitsInInteger(ch_int);
    }
    return result;
}

int getLucky(std::string s, int k) {
    int current_sum = ConvertCharsAndSumUpDigits(s);
    // Conversion and Transform #1 are completed. Start from Transform #2 
    for (int idx = 1; idx < k; ++idx) {
        if (current_sum < 10) {
            return current_sum;
        }
        current_sum = SumUpDigitsInInteger(current_sum);
    }       
    return current_sum; 
}

void RunTestCases() {
    assert (getLucky("iiii", 1) == 36);
    assert (getLucky("leetcode", 2) == 6);
    assert (getLucky("zbax", 2) == 8);
    assert (getLucky("aaaa", 10) == 4);
    assert (getLucky("a", 1) == 1);
    assert (getLucky("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", 10) == 8);
    assert (getLucky("iiii", 2) == 9);
}

int main() {
    RunTestCases();
    return 0;
}