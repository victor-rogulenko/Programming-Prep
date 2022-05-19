// LeetCode: 386. Lexicographical Numbers
// 386-Lexicographical-Numbers.cpp
// Created by Victor Rogulenko
// [2022-05-19 17:33]

// Given an integer n, return all the numbers in the range [1, n] 
// sorted in lexicographical order.
// You must write an algorithm that runs in O(n) time and uses 
// O(1) extra space. 

// 1 <= n <= 5 * 10^4

// MAJOR IDEA: Start from 0

#include <vector>

class Solution {
    std::vector<int> result;
    int max_num;
public:
    void dfs(int val, int border) {
        if (val >= border) {
            return;
        }
        if (val != 0) {
            result.push_back(val);
            dfs(val*10, std::min(max_num, (val+1)*10));   
        }
        dfs(val+1, std::min(border, val+10));
    }
    
    std::vector<int> lexicalOrder(int n) {
        max_num = n + 1;
        dfs(0, max_num);
        return result;
    }
};