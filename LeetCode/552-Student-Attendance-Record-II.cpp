// LeetCode: 552. Student Attendance Record II
// 552-Student-Attendance-Record-II.cpp
// Created by Victor Rogulenko
// [2022-08-16 19:03]

// An attendance record for a student can be represented as a string 
// where each character signifies whether the student was absent, late, 
// or present on that day. The record only contains the following 
// three characters:
// - 'A': Absent.
// - 'L': Late.
// - 'P': Present.
// Any student is eligible for an attendance award if they meet both of 
// the following criteria:
// - The student was absent ('A') for strictly fewer than 2 days total.
// - The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of 
// length n that make a student eligible for an attendance award. The answer 
// may be very large, so return it modulo 10^9 + 7.
// 1 <= n <= 10^5

// MAJOR IDEA: DP rule2[N] = 2*rule2[N-1] - rule2[N-4], Then add Rule 1
// Time: O(N). Space: O(N)

#include <vector>

const int modulo = (int)(1e9) + 7;

class Solution {
public:
    int checkRecord(int n) {
        // Apply rule 2: Ls only
        std::vector<long> rule2 = {1, 2, 4, 7};
        rule2.resize(n + 1);
        for (int idx = 4; idx <= n; ++idx) {
            rule2[idx] = ((2 * rule2[idx - 1]) % modulo + 
                          modulo - rule2[idx - 4]) % modulo;
        }
        
        // Apply rule 1: add As
        long result = rule2[n]; // No As
        for (int idx = 1; idx <= n; ++idx) {
            result += (rule2[idx - 1] * rule2[n - idx]);
            result %= modulo;
        }
        
        return (int)(result);
    }
};

// #bugs = 2