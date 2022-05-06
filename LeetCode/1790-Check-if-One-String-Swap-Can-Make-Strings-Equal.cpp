// LeetCode: 1790. Check if One String Swap Can Make Strings Equal
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>

bool areAlmostEqual(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    std::string mismatch1, mismatch2;
    for (int idx = 0; idx < s1.length(); ++idx) {
        if (s1[idx] != s2[idx]) {
            mismatch1 += s1[idx];
            mismatch2 += s2[idx];
        }
    }
    if ((!mismatch1.empty()) && (mismatch1.length() != 2)) {
        return false;
    }
    return (mismatch1 == std::string(mismatch2.rbegin(), mismatch2.rend()));    
}

// 1 <= s1.length, s2.length <= 100
// s1.length == s2.length
// s1 and s2 consist of only lowercase English letters.

void RunTestCases() {
    assert(areAlmostEqual("bank", "kanb") == true);
    assert(areAlmostEqual("attack", "defend") == false);
    assert(areAlmostEqual("kelb", "kelb") == true);
    assert(areAlmostEqual("a", "a") == true);
    assert(areAlmostEqual("abc", "aec") == false);
    assert(areAlmostEqual("a", "c") == false);
}

int main() {
    RunTestCases();
    return 0;
}