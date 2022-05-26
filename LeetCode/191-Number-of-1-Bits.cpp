// LeetCode: 191. Number of 1 Bits
// 191-Number-of-1-Bits.cpp
// Created by Victor Rogulenko
// [2022-05-26 14:23]	

// Write a function that takes an unsigned integer and returns 
// the number of '1' bits it has (also known as the Hamming weight).

// The input must be a binary string of length 32.

// MAJOR IDEA: res += n % 2; n /= 2; OR res += ((n & (1 << pow)) > 0);

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int pow = 0; pow < 32; ++pow) {
            res += ((n & (1 << pow)) > 0);
        }
        return res;
    }
};