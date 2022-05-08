// LeetCode: 1071. Greatest Common Divisor of Strings 
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <string>
#include <numeric> // gcd

bool checkStringIsDivisible(const std::string& str1, const std::string& div) {
    int idx_str1 = 0, idx_div = 0;
    while (idx_str1 < str1.length()) {
        if (str1[idx_str1] != div[idx_div]) {
            return false;
        }
        ++idx_str1;
        ++idx_div;
        if (idx_div >= div.length()) {
            idx_div = idx_div % div.length();
        }
    }
    return (idx_div == 0);
}

std::string gcdOfStrings(std::string str1, std::string str2) {
    int gcd_length = std::gcd(str1.length(), str2.length());
    std::string candidate = str1.substr(0, gcd_length);
    if (checkStringIsDivisible(str1, candidate) &&
        checkStringIsDivisible(str2, candidate)) {
        return candidate;
    } else {
        return "";
    }
}

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of English uppercase letters.

void RunTestCases() {
    assert(gcdOfStrings("ABCABC", "ABC") == "ABC");
    assert(gcdOfStrings("AAAAA", "AAAA") == "A");
    assert(gcdOfStrings("ABABAB", "ABAB") == "AB");
    assert(gcdOfStrings("LEET", "CODE") == "");
    assert(gcdOfStrings("A", "A") == "A");
}

int main() {
    RunTestCases();
    return 0;
}