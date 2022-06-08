// LeetCode: 1492. The kth Factor of n
// 1492-The-kth-Factor-of-n.cpp
// Created by Victor Rogulenko
// [2022-06-08 16:18]

// You are given two positive integers n and k. A factor of an integer n is 
// defined as an integer i where n % i == 0.
// Consider a list of all factors of n sorted in ascending order, return 
// the kth factor in this list or return -1 if n has less than k factors.
// 1 <= k <= n <= 1000
// Follow up:
// Could you solve this problem in less than O(n) complexity?

// MAJOR IDEA: check factors up to sqrt(n) and 
// from (int)sqrt(n) to 1 (res = n/factor)

// SOLUTION 1. O(n)

class Solution {
public:
    int kthFactor(int n, int k) {
        for (int factor = 1; factor <= n; ++factor) {
            k -= (n % factor == 0);
            if (!k) {
                return factor;
            }
        }
        return -1;
    }
};

// SOLUTION 2. O(sqrt(n))

class Solution2 {
public:   
    int kthFactor(int n, int k) {
        for (int factor = 1; factor < std::sqrt(n); ++factor) {
            if (n % factor == 0 && --k == 0) {
                return factor;
            }
        }
        
        for (int factor = (int)(std::sqrt(n)); factor != 0; --factor) {
            if (n % factor == 0 && --k == 0) {
                return n/factor;
            }
        }
        
        return -1;
    }
};