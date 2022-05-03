// LeetCode: 844. Backspace String Compare
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

bool backspaceCompare(std::string s, std::string t) {
    int idx_s = s.length() - 1;
    int idx_t = t.length() - 1;
    int ctr_bsp_s = 0;
    int ctr_bsp_t = 0;
    while ((idx_s >= 0) || (idx_t >= 0)) {
    //  Find characters remaining after backspace
        while (idx_s >= 0) {
            if (s[idx_s] == '#') {
                ++ctr_bsp_s;
                --idx_s;
            } else if (ctr_bsp_s > 0) {
                --ctr_bsp_s;
                --idx_s;
            } else break;
        }
        while (idx_t >= 0) {
            if (t[idx_t] == '#') {
                ++ctr_bsp_t;
                --idx_t;
            } else if (ctr_bsp_t > 0) {
                --ctr_bsp_t;
                --idx_t;
            } else break;
        }
    //  Check that the characters are the same
        if ((idx_s >= 0) && (idx_t >= 0) && (s[idx_s] != t[idx_t])) {
            return false;
        }
    //  Check if one of the strigs ended before the other
        if ((idx_s >= 0) != (idx_t >= 0)) {
            return false;
        }
        --idx_s;
        --idx_t;
    }
    return true;  
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