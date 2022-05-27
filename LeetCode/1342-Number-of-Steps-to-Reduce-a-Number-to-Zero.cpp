// LeetCode: 1342. Number of Steps to Reduce a Number to Zero
// 1342-Number-of-Steps-to-Reduce-a-Number-to-Zero.cpp
// Created by Victor Rogulenko
// [2022-05-27 11:16]  

// Given an integer num, return the number of steps to reduce it to zero.
// In one step, if the current number is even, you have to divide it by 2, 
// otherwise, you have to subtract 1 from it.

// 0 <= num <= 10^6

// MAJOR IDEA: Count # of 1's in binary representation + max power of 2

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0, maxPow = 0;
        for (int pow = 0; pow < 31; ++pow) {
            if ((num & (1 << pow)) > 0) {
                ++cnt;
                maxPow = pow;
            }
        }
        return cnt + maxPow;
    }
};

// 14 -> 7 -> 6 -> 3 -> 2 -> 1 -> 0

// 14 = 1110(2)
// cnt = 3
// maxPow = 3

// 8 = 1000(2)
// cnt = 1
// maxPow = 3

// #bugs = 0