// LeetCode: 715. Range Module
// 715-Range-Module.cpp
// Created by Victor Rogulenko
// [2022-08-04 23:18]	

// A Range Module is a module that tracks ranges of numbers. 
// Design a data structure to track the ranges represented as 
// half-open intervals and query about them.
// A half-open interval [left, right) denotes all the real numbers x 
// where left <= x < right.
// Implement the RangeModule class:
// - RangeModule() Initializes the ob ject of the data structure.
// - void addRange(int left, int right) Adds the half-open interval [left, right), 
// tracking every real number in that interval. Adding an interval that 
// partially overlaps with currently tracked numbers should add any numbers 
// in the interval [left, right) that are not already tracked.
// - boolean queryRange(int left, int right) Returns true if every real number 
// in the interval [left, right) is currently being tracked, and false otherwise.
// - void removeRange(int left, int right) Stops tracking every real number 
// currently being tracked in the half-open interval [left, right).

// MAJOR IDEA: Store a sorted map (left_border, right_border) of disjoint intervals.
// Use binary search to look up the position of a point in the map. When performing queries,
// make sure the intervals remain disjoint.
// Time: O(M log N). Space: O(N), N - number of ranges, M - number of non-adding queries

#include <vector>
#include <map>
#include <algorithm> // std::max, std::min
#include <utility> // std::pair

class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto position = findPosition(left);
        int start = left, finish = right;
        while (position != ranges.end() && position->first <= finish) {
            start = std::min(start, position->first);
            finish = std::max(finish, position->second);
            ranges.erase(position++);
        }
        ranges[start] = finish;
    }
    
    bool queryRange(int left, int right) {
        auto position = findPosition(left);
        return (position != ranges.end() && 
                position->first <= left &&
                position->second >= right);
    }
    
    void removeRange(int left, int right) {
        auto position = findPosition(left);
        std::vector<std::pair<int,int>> rangesToKeep;
        while (position != ranges.end() && position->first < right) {
            if (position->first < left) {
                rangesToKeep.push_back({position->first, left});
            }
            if (position->second > right) {
                rangesToKeep.push_back({right, position->second});
            }
            ranges.erase(position++);
        }
        for (auto [x, y] : rangesToKeep) {
            ranges[x] = y;
        }
    }
    
private:
    std::map<int,int> ranges;
    
    std::map<int,int>::iterator findPosition(int left) {
        auto position = ranges.upper_bound(left);
        if (position != ranges.begin()) {
            --position;
        }
        if (position != ranges.end() && position->second < left) {
            ++position;
        }
        return position;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

// #bugs = 7

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

// #bugs = 7