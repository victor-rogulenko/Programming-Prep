// LeetCode: 56. Merge Intervals
// 56-Merge-Intervals.cpp
// Created by Victor Rogulenko
// [2022-06-06 15:20]	

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

// 1 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^4

// MAJOR IDEA: Sort intervals in increasing order of left ends. 
// Then iterate over the intervals and check overlaps

#include <vector>
#include <algorithm> // std::sort

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> result;    
        // Sort intervals in increasing order of left ends;
        std::sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        
        for (int idx = 1; idx < intervals.size(); ++idx) {
            if (result.back()[1] < intervals[idx][0]) {
                // The previous and the current intervals are
                // not overlapping 
                result.push_back(intervals[idx]);
            } else {
                // Merge idx with the previous interval
                result.back()[1] = std::max(result.back()[1], intervals[idx][1]);
            }
        }
        
        return result;
    }
};

// #bugs = 0