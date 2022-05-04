// LeetCode 1544. Make The String Great
// Created by Victor Rogulenko

#include <string>
#include <cassert>

bool checkThePairIsBad(char one, char two) {
    if (((int)(one) - (int)('a') == (int)(two) - (int)('A')) ||
       ((int)(one) - (int)('A') == (int)(two) - (int)('a'))) {
       return true;
    }
    return false;
}

int findBadPair(const std::string& s) {
    if (s.length() < 2) {
        return s.length();
    }
    for (int idx = 1; idx < s.length(); ++idx) {
        if (checkThePairIsBad(s[idx], s[idx-1])) {
            return (idx-1);
        }
    }
    return s.length();
}

std::string makeGood(std::string s) {
    if (s.length() < 2) {
        return s;
    }
    bool isGood = false;
    do {
        int bad_pair_idx = findBadPair(s);
        if (bad_pair_idx != s.length()) {
            s.erase(bad_pair_idx, 2);
        } else {
            isGood = true;
        }
    } while (!isGood);
    return s;
}

void RunTestCases() {
    assert (makeGood("s") == "s");
    assert (makeGood("abBAcC") == "");
    assert (makeGood("leEeetcode") == "leetcode");
    assert (makeGood("aBcDeF") == "aBcDeF");
    assert (makeGood("aAa") == "a");
    assert (makeGood("DaAD") == "DD");
}

int main() {
    RunTestCases();
    return 0;
}