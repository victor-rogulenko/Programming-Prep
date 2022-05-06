// LeetCode: 205. Isomorphic Strings
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <vector>
#include <iostream>

const int AlphabetSize = 300;  // must be greater than 256, size of ascii
const int MinVal = 130; // to offset negative (int)(ch) such as §

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    // Need 2 vectors to ensure 1-to-1 matching
    // 1 vector guarantees only N-to-1 matching
    std::vector<int> matching_s(AlphabetSize, -1);
    std::vector<int> matching_t(AlphabetSize, -1);

    for (int idx = 0; idx < s.length(); ++idx) {
        int s_val = (int)(s[idx]) + MinVal;
        int t_val = (int)(t[idx]) + MinVal;

        if ((matching_s[s_val] != -1) && 
            (matching_s[s_val] != t_val)) {
            return false;
        }
        if ((matching_t[t_val] != -1) && 
            (matching_t[t_val] != s_val)) {
            return false;
        }
        matching_s[s_val] = t_val;
        matching_t[t_val] = s_val;
    }
    return true;    
}

// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

void RunTestCases() {
    assert(isIsomorphic("egg", "add") == true);
    assert(isIsomorphic("foo", "bar") == false);
    assert(isIsomorphic("paper", "title") == true);
    assert(isIsomorphic("abc", "ooo") == false);
    assert(isIsomorphic("ooo", "abc") == false);
    assert(isIsomorphic("a", "b") == true);
    assert(isIsomorphic("a", "a") == true);
    assert(isIsomorphic("½", "§") == true);
}

int main() {
    RunTestCases();
    return 0;
}