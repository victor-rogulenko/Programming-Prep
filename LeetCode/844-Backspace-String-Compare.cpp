// LeetCode: 844. Backspace String Compare
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

std::vector<bool> buildMaskOfRemainingCharacters(const std::string& s) {
    std::vector<bool> result(s.length(), true); //true if not erased
    int idx = 0;
    while (idx < s.length()) {
        if (s[idx] == '#') {
            result[idx] = false;
            int jdx = idx - 1;
            while ((jdx >= 0) && (!result[jdx])) {
                --jdx;
            }
            if (jdx >= 0) {
                result[jdx] = false;
            }
        }
        ++idx;
    }
    return result;
}

bool backspaceCompare(std::string s, std::string t) {
    std::vector<bool> mask_s = buildMaskOfRemainingCharacters(s);
    std::vector<bool> mask_t = buildMaskOfRemainingCharacters(t);
    int idx_s = 0, idx_t = 0;
    while ((idx_s < s.length()) && (idx_t < t.length())) {
        while ((idx_s < s.length()) && (!mask_s[idx_s])) {
            ++idx_s;
        }
        while ((idx_t < t.length()) && (!mask_t[idx_t])) {
            ++idx_t;
        }
        if (((idx_s < s.length()) && (idx_t >= t.length())) ||
            ((idx_s >= s.length()) && (idx_t < t.length()))) {
            return false;
        }
        if ((idx_s < s.length()) && (idx_t < t.length()) && (s[idx_s] != t[idx_t])) {
            return false;
        }
        ++idx_s;
        ++idx_t;
    }
    while ((idx_s < s.length()) && (!mask_s[idx_s])) {
        ++idx_s;
    }
    while ((idx_t < t.length()) && (!mask_t[idx_t])) {
        ++idx_t;
    }
    return ((idx_s >= s.length()) & (idx_t >= t.length()));    
}

void RunTestCases() {
    assert (backspaceCompare("ab#c", "ad#c") == true);
    assert (backspaceCompare("ab##", "c#d#") == true);
    assert (backspaceCompare("a#c", "b") == false);
    assert (backspaceCompare("a", "b") == false);
    assert (backspaceCompare("#", "#") == true);
    assert (backspaceCompare("abcd#####a", "a") == true);
    assert (backspaceCompare("abab", "abab") == true);
    assert (backspaceCompare("abab", "abab#") == false);
    assert (backspaceCompare("abcd", "abcdabcd####") == true);
}

int main() {
    RunTestCases();
    return 0;
}