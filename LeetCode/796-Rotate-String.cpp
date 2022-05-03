// LeetCode: 796. Rotate String
// Created by Victor Rogulenko

#include <cassert>
#include <string>

bool rotateString(const std::string& s, const std::string& goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    int goal_idx = 0;
    for (int s_idx = 0; s_idx < s.length(); ++s_idx) {
        if (goal[goal_idx] == s[s_idx]) {
            ++goal_idx;
        } else if (goal[0] == s[s_idx]) {
            goal_idx = 1;
        } else {
            goal_idx = 0;
        }     
    }
    int s_idx = 0;
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
}

int main() {
    RunTests();
    return 0;
}

