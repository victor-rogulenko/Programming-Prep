// LeetCode: 2275. Largest Combination With Bitwise AND Greater Than Zero
// 293-2275-Largest-Combination-With-Bitwise-AND-Greater-Than-Zero.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// The bitwise AND of an array nums is the bitwise AND of all integers in nums.
// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates. Evaluate 
// the bitwise AND of every combination of numbers of candidates. Each 
// number in candidates may only be used once in each combination.
// Return the size of the largest combination of candidates with a bitwise 
// AND greater than 0.

// 1 <= candidates.length <= 10^5
// 1 <= candidates[i] <= 10^7

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCandidates(int bit, const vector<int>& candidates) {
        int result = 0;
        for (auto val : candidates) {
            result += ((val & bit) > 0);
        }
        return result;
    }

    int largestCombination(vector<int>& candidates) {
        int result = 0;
        int bit = 0;
        for (int move = 0; move < 25; ++move) {
            int bit = (1 << move);
            int cur = countCandidates(bit, candidates);
            result = max(result, cur);
        }
        return result;
    }
};

void TestCase(vector<int> input, int expected) {
    int result = Solution().largestCombination(input);
    std::cout << "result = " << result << ", expected = " << expected << "\n";
    assert(result == expected);
}

void RunTestCases() {
    TestCase({16,17,71,62,12,24,14}, 4);
    TestCase({8,8}, 2);
    TestCase({1,8}, 1);
}

int main() {
    RunTestCases();
    return 0;
}