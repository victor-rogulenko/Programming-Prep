// LeetCode: 3. Longest Substring Without Repeating Characters
// Created by Victor Rogulenko
// May 07, 2022

#include <cassert>
#include <string>
#include <vector>

const int ChShift = 128;
const int AlphabetSize = 300;

int chToInt(char ch) {
    return (int)(ch) + ChShift;
    // ChShift takes care of potentially negative values of (int)(ch)
}

int lengthOfLongestSubstring(std::string s) {
    if (s.length() < 2) {
        return s.length();
    }
    int result = 0;
    std::vector<bool> seen(AlphabetSize, false);
    // Use 2 ptrs: start and finish
    int start = 0;
    int finish = 0;
    while (finish + 1 < s.length()) {
        seen[chToInt(s[start])] = true;
        seen[chToInt(s[finish])] = true;
        // Move finish as far as we can
        ++finish;
        while ((finish < s.length()) && (!seen[chToInt(s[finish])])) {
            seen[chToInt(s[finish])] = true;
            ++finish;
        }

        result = ((finish - start > result) ? (finish - start) : result);

        // Move start to preserve uniqueness of characters
        while ((start < finish) && (s[start] != s[finish])) {
            seen[chToInt(s[start])] = false;
            ++start;
        }

        // Step over the repeating char
        if (start < s.length()) {
            seen[chToInt(s[start])] = false;
            ++start;            
        }
    }
    return result;    
}

// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces.

void RunTestCases() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);    
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring("a") == 1);
    assert(lengthOfLongestSubstring("aa") == 1);
    assert(lengthOfLongestSubstring("aa123") == 4);
    assert(lengthOfLongestSubstring("abcdaabcde") == 5);
}

int main() {
    RunTestCases();
    return 0;
}