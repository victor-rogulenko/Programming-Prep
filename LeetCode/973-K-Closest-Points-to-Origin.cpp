// LeetCode: 973. K Closest Points to Origin
// 973-K-Closest-Points-to-Origin.cpp
// Created by Victor Rogulenko
// [2022-06-07 17:57]	

// Given an array of points where points[i] = [xi, yi] represents a point 
// on the X-Y plane and an integer k, return the k closest points to 
// the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean 
// distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be 
// unique (except for the order that it is in).

// 1 <= k <= points.length <= 10^4
// -10^4 < xi, yi < 10^4

// MAJOR IDEA: Sort points by their distance from the origin

#include <vector>
#include <algorithm> // std::sort

bool pointsLess(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    return lhs[0]*lhs[0] + lhs[1]*lhs[1] < rhs[0]*rhs[0] + rhs[1]*rhs[1];
}

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), pointsLess);
        return std::vector<std::vector<int>>(points.begin(), points.begin()+k);
    }
};