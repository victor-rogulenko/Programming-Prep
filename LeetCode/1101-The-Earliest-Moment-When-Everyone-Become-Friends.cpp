// LeetCode: 1101. The Earliest Moment When Everyone Become Friends
// 1101-The-Earliest-Moment-When-Everyone-Become-Friends.cpp
// Created by Victor Rogulenko
// [2022-08-16 14:22]

// There are n people in a social group labeled from 0 to n - 1. 
// You are given an array logs where logs[i] = [timestampi, xi, yi] 
// indicates that xi and yi will be friends at the time timestampi.
// Friendship is symmetric. That means if a is friends with b, then 
// b is friends with a. Also, person a is acquainted with a person b if 
// a is friends with b, or a is a friend of someone acquainted with b.
// Return the earliest time for which every person became acquainted 
// with every other person. If there is no such earliest time, return -1.
// 2 <= n <= 100
// 1 <= logs.length <= 10^4
// logs[i].length == 3
// 0 <= timestampi <= 10^9
// 0 <= xi, yi <= n - 1
// xi != yi
// All the values timestampi are unique.
// All the pairs (xi, yi) occur at most one time in the input.

// MAJOR IDEA: Use Union Find (Disjoint Set Union)
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
// n is small, so no need for path splitting and merging by rank
// Time: O(M log M). Space: O(N). M - size of logs

#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    int earliestAcq(std::vector<std::vector<int>>& logs, int n) {
        std::sort(logs.begin(), logs.end());
        parents.resize(n);
        for (int idx = 0; idx < n; ++idx) {
            parents[idx] = idx;
        }
        int result = n;
        for (const auto& log : logs) {
            int x = findParent(log[1]);
            int y = findParent(log[2]);
            if (x != y) {
                --result;
                parents[x] = y;
                if (result == 1) {
                    return log[0];
                }
            }
        }
        
        return -1;
    }

private:
    std::vector<int> parents;
    
    int findParent(int x) {
        return (x == parents[x] ? x : findParent(parents[x]));
    }
};

// #bugs = 1

