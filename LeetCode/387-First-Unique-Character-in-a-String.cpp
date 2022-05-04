// LeetCode: 387. First Unique Character in a String
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

const int AlphabetSize = 26;

std::vector<int> buildCharLibraryWithOccurances(const std::string& s) {
    std::vector<int> result(AlphabetSize, 0);
    for (auto& ch : s) {
        ++result[(int)(ch) - (int)('a')];
    }
    return result;
};

int firstUniqChar(std::string s) {
    std::vector<int> char_occurances = buildCharLibraryWithOccurances(s);
    int unique_char_idx = -1;
    for (int idx = 0; idx < s.length(); ++idx) {
        if (char_occurances[(int)(s[idx]) - (int)('a')] == 1) {
            return idx;
        }
    }
    return -1;    
};

void RunTestCases() {
    assert (firstUniqChar("leetcode") == 0);
    assert (firstUniqChar("loveleetcode") == 2);
    assert (firstUniqChar("aabb") == -1);
    assert (firstUniqChar("a") == 0);
    assert (firstUniqChar("aaaaaaaaaaa") == -1);
    assert (firstUniqChar("abcabcabc") == -1);
    assert (firstUniqChar("abcabcz") == 6);
};

int main() {
    RunTestCases();
    return 0;
}