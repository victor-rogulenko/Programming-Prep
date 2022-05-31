// LeetCode: BW Contest 79 2285. Maximum Total Importance of Roads
// 79-2285-Maximum-Total-Importance-of-Roads.cpp
// Created by Victor Rogulenko
// May 28, 2022

// You are given an integer n denoting the number of cities in a country. 
// The cities are numbered from 0 to n - 1.
// You are also given a 2D integer array roads where roads[i] = [ai, bi] 
// denotes that there exists a bidirectional road connecting cities ai and bi.
// You need to assign each city with an integer value from 1 to n, where 
// each value can only be used once. The importance of a road is then defined 
// as the sum of the values of the two cities it connects.
// Return the maximum total importance of all roads possible after assigning 
// the values optimally.

// 2 <= n <= 5 * 10^4
// 1 <= roads.length <= 5 * 10^4
// roads[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no duplicate roads.

// MAJOR IDEA: Assign greater values to nodes with most edges

#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> cityImportance(n, 0);
        
        for (const auto& road : roads) {
            ++cityImportance[road[0]];
            ++cityImportance[road[1]];
        }
        
        std::sort(cityImportance.begin(), cityImportance.end());
        
        long long result = 0;
        
        for (int idx = n-1; idx >=0; --idx) {
            result += (long long)(cityImportance[idx]) * (long long)(idx + 1);
        }
        
        return result;
    }
};

// #bugs = 0