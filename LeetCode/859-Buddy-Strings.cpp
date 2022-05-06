// LeetCode: 859. Buddy Strings
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <vector>

bool hasDuplicates(const std::string s) {
    std::vector<int> char_occurances(26, 0);
    for (auto& ch : s) {
        int ch_int = (int)(ch) - (int)('a');
        ++char_occurances[ch_int];
        if (char_occurances[ch_int] > 1) {
            return true;
        }
    }
    return false;
}

bool buddyStrings(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    std::string mismatch_s, mismatch_goal;
    for (int idx = 0; idx < s.length(); ++idx) {
        if (s[idx] != goal[idx]) {
            mismatch_s += s[idx];
            mismatch_goal += goal[idx];
        }
        if (mismatch_s.length() > 2) {
            return false;
        }
    }
    // If the number of mismatched chars is neither 0 nor 2, return false.
    // One swap isn't enough
    if ((!mismatch_s.empty()) && (mismatch_s.length() != 2)) {
        return false;
    }
    // If the mismatched charactes are the same, return true, otherwise false
    if (mismatch_s.length() == 2) {
        if (mismatch_s == std::string(mismatch_goal.rbegin(), mismatch_goal.rend())) {
            return true;
        } else {
            return false;
        }
    }
    // s and goal are equal. If s has duplicates, we'll swap them, and return true
    // Else (e.g. s == goal == "ab") return false
    return hasDuplicates(s);
}

// 1 <= s.length, goal.length <= 2 * 10^4
// s and goal consist of lowercase letters.

void RunTestCases() {
    assert(buddyStrings("ab", "ba") == true);
    assert(buddyStrings("ab", "ab") == false);
    assert(buddyStrings("aa", "aa") == true);
    assert(buddyStrings("a", "a") == false);
    assert(buddyStrings("ab", "a") == false);
    assert(buddyStrings("ab", "aba") == false);
    assert(buddyStrings("ebcda", "abcde") == true);
}

int main() {
    RunTestCases();
    return 0;
}