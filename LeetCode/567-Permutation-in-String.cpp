// LeetCode: 567. Permutation in String // 567-Permutation-in-String.cpp
// Created by Victor Rogulenko
// May 12, 2022

// Given two strings s1 and s2, return true if s2 
// contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations 
// is the substring of s2.

// 1 <= s1.length, s2.length <= 10^4
// s1 and s2 consist of lowercase English letters.

#include <cassert>
#include <string>
#include <vector>
#include <iostream>

const int AlphabetSize = 26;

int chToInt(char ch) {
    return (int)(ch) - (int)('a');
}

bool checkInclusion(const std::string& small, const std::string& large) {
    if (small.size() > large.size()) {
        return false;
    }
    std::vector<int> goal_cnt(AlphabetSize, 0);
    for (auto ch : small) {
        ++goal_cnt[chToInt(ch)];
    }
    int cnt_diff_letters = 0;
    for (auto elm : goal_cnt) {
        cnt_diff_letters += (elm > 0);
    }
    
    int start = 0; 
    while (start < large.size()) {
        int finish = start;
        std::vector<int> cur_cnt(AlphabetSize, 0);
        // Find the first time after current position when all letters of small
        // are present in large
        int cnt_letters = 0;
        while ((finish < large.size()) && (cnt_letters != cnt_diff_letters)) {
            ++cur_cnt[chToInt(large[finish])];
            if (cur_cnt[chToInt(large[finish])] == goal_cnt[chToInt(large[finish])]) {
                ++cnt_letters;
            }
            ++finish;
        }
        // Candidate for the permutation: substring in large of length small.size() 
        // ending at finish - 1. If it is not the required permutation, there're no such
        // permutations from the previous position up to finish
        if ((finish - start == small.size()) && (cnt_letters == cnt_diff_letters)) {
            return true;
        }
        if ((finish == large.size()) && (finish - start == small.size())) {
            return false;
        }
        start = finish - small.size();
    }

    return false;    
}

void TestCase(std::string s1, std::string s2, bool verdict) {
    std::cout << checkInclusion(s1, s2) << "\n";
    assert (checkInclusion(s1, s2) == verdict);
}

void RunTestCases() {
    TestCase("ab", "eidbaooo", true);
    TestCase("ab", "eidboaoo", false);
    TestCase("z", "z", true);
    TestCase("z", "zzz", true);
    TestCase("z", "aaz", true);
    TestCase("z", "a", false);
    TestCase("z", "aaa", false);
    TestCase("zaza", "aaaaabzza", false);
    TestCase("zaza", "aaaaabzzaa", true);
    TestCase("zzzz", "aazzabzzaa", false);
    TestCase("zzzz", "aazzabzzzz", true);
    TestCase("zzab", "aazzaxbzzzz", false);
    TestCase("zzab", "aazzabzzzz", true);
    TestCase("zzab", "aazzazzzbzzzz", false);
}

int main() {
    RunTestCases();
    return 0;
}