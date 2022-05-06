// LeetCode: 415. Add Strings
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>

std::string addStrings(std::string num1, std::string num2) {
    // Add leading zeros to make strings of the same length
    if (num1.length() < num2.length()) {
        num1.insert(0, num2.length() - num1.length(), '0');
    } else if (num1.length() > num2.length()) {
        num2.insert(0, num1.length() - num2.length(), '0');
    }
    // Reverse the strings
    num1 = std::string(num1.rbegin(), num1.rend());
    num2 = std::string(num2.rbegin(), num2.rend());
    // Sum up digits one by one
    int extra = 0;
    std::string result = "";
    for (int idx = 0; idx < num1.length(); ++idx) {
        int digit_sum = (int)(num1[idx]) + (int)(num2[idx]) - 2 * (int)('0') + extra;
        extra = 0;
        if (digit_sum > 9) {
            extra = 1;
            digit_sum %= 10;
        }
        result += std::to_string(digit_sum);
    }
    if (extra > 0) {
        result += '1';
    }
    return std::string(result.rbegin(), result.rend());        
}

// 1 <= num1.length, num2.length <= 104
// num1 and num2 consist of only digits.
// num1 and num2 don't have any leading zeros except for the zero itself.

void RunTestCases() {
    assert(addStrings("11", "123") == "134");
    assert(addStrings("123", "11") == "134");
    assert(addStrings("456", "77") == "533");
    assert(addStrings("0", "0") == "0");
    assert(addStrings("9999", "0") == "9999");    
    assert(addStrings("9999", "1") == "10000");    
    assert(addStrings("9999", "1000") == "10999");
    assert(addStrings("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") == "2000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");    
}

int main() {
    RunTestCases();
    return 0;
}