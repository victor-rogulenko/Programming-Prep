// LeetCode: 2269. Find the K-Beauty of a Number
// 78-2269-Find-the-K-Beauty-of-a-Number.cpp
// Created by Victor Rogulenko
// May 14, 2022

#include <cassert>
#include <string>
#include <iostream>

// The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

// It has a length of k.
// It is a divisor of num.
// Given integers num and k, return the k-beauty of num.

// 1 <= num <= 109
// 1 <= k <= num.length (taking num as a string)

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int start = 0;
        std::string str = std::to_string(num);
        int result = 0;

        while (start + k <= str.length()) {
            std::string candidate = str.substr(start, k);
            int cand_num = std::stoi(candidate);
            if ((cand_num != 0) && (num % cand_num == 0)) {
                ++result;
            }
            ++start;
        }
        return result;
    }
};

void RunTestCases() {
    assert(Solution().divisorSubstrings(240, 2) == 2);
    assert(Solution().divisorSubstrings(430043, 2) == 2);
    assert(Solution().divisorSubstrings(1, 10) == 0);
}

int main() {
    RunTestCases();
    return 0;
}