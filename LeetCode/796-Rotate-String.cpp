// LeetCode: 796. Rotate String
// Created by Victor Rogulenko

// Based on Knuth–Morris–Pratt algorithm
// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

#include <cassert>
#include <string>
#include <vector>

std::vector<int> BuildFailureTableKMP(const std::string& str) {
    std::vector<int> result(str.length() + 1, -1);
    int pos = 1;
    int cnd = 0;
    while (pos < str.length()) {
        if (str[pos] == str[cnd]) {
            result[pos] = result[cnd];
        } else {
            result[pos] = cnd;
            while ((cnd >= 0) && (str[cnd] != str[pos])) {
                cnd = result[cnd];
            }
        }
        ++pos;
        ++cnd;
    }
    return result;
}

bool rotateString(const std::string& s, const std::string& goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    int goal_idx = 0;
    int s_idx = 0;
    std::vector<int> FailureTable = BuildFailureTableKMP(goal);
    while (s_idx < s.length()) {
        if (goal[goal_idx] == s[s_idx]) {
            ++goal_idx;
            ++s_idx;
        } else {
            goal_idx = FailureTable[goal_idx];
            if (goal_idx < 0) {
                ++goal_idx;
                ++s_idx;
            } 
        }     
    }
    s_idx = 0;
    while (goal_idx < goal.length()) {
        if (goal[goal_idx] != s[s_idx]) {
            return false;
        }
        ++goal_idx;
        ++s_idx;
    }
    return true;
}

void RunTests() {
    assert (rotateString("a", "aa") == false);
    assert (rotateString("a", "a") == true);
    assert (rotateString("abc", "bca") == true);
    assert (rotateString("ababc", "abcab") == true);
    assert (rotateString("abcde", "abced") == false);
    assert (rotateString("abcde", "cdeab") == true);
    assert (rotateString("abdabcabc", "abcabdabc") == true);
}

int main() {
    RunTests();
    return 0;
}

