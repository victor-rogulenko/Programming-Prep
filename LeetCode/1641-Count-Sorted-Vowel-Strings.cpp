// LeetCode: 1641. Count Sorted Vowel Strings
// Created by Victor Rogulenko
// May 11, 2022

// Given an integer n, return the number of strings of length n 
// that consist only of vowels (a, e, i, o, u) and are 
// lexicographically sorted.

// A string s is lexicographically sorted if for all valid i, 
// s[i] is the same as or comes before s[i+1] in the alphabet.

// 1 <= n <= 50

#include <cassert>
#include <vector>
#include <numeric> // std::accumulate

int countVowelStrings(int n) {
    const int vowel_count = 5;
    std::vector<int> cnt_vowel_strings_starting_from_i(vowel_count, 1);
    // Iter 0 is taken care of above
    for (int iter = 1; iter < n; ++iter) {
        for (int idx = 0; idx < vowel_count; ++idx) {
            for (int jdx = idx + 1; jdx < vowel_count; ++jdx) {
                cnt_vowel_strings_starting_from_i[idx] += 
                    cnt_vowel_strings_starting_from_i[jdx];
            }
        }
    }
    return std::accumulate(cnt_vowel_strings_starting_from_i.begin(),
                           cnt_vowel_strings_starting_from_i.end(),
                           0);
}

void RunTestCases() {
    assert(countVowelStrings(1) == 5);
    assert(countVowelStrings(2) == 15);
    assert(countVowelStrings(33) == 66045);
    assert(countVowelStrings(50) > 0);
}

int main() {
    RunTestCases();
    return 0;
}