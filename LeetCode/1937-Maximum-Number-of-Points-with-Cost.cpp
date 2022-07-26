// LeetCode: 1937. Maximum Number of Points with Cost
// 1937-Maximum-Number-of-Points-with-Cost.cpp
// Created by Victor Rogulenko
// July 26, 2022

// You are given an m x n integer matrix points (0-indexed). 
// Starting with 0 points, you want to maximize the number 
// of points you can get from the matrix.
// To gain points, you must pick one cell in each row. Picking 
// the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from 
// the cell that you picked in the previous row. For every two 
// adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells 
// at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// m == points.length
// n == points[r].length
// 1 <= m, n <= 10^5
// 1 <= m * n <= 10^5
// 0 <= points[r][c] <= 10^5

// MAJOR IDEA. DP + Precompute Left and Right. 
// dp[idx][jdx] = max result if points[idx][jdx] was chosen last. 
// Store 2 rows only. Precompute left[jdx] and right[jdx] - max values if we consider 
// only values to the left (and to the right) of jdx. Then take their max.
// Time: O(NM). Space: O(M)

#include <vector>

class Solution {
public:
    long long maxPoints(const std::vector<std::vector<int>>& points) {
        int nrows = points.size();
        int ncols = points[0].size();
        
        std::vector<long long> prev(ncols, 0);
        for (int idx = 0; idx < ncols; ++idx) {
            prev[idx] = points[0][idx];
        }
        
        std::vector<long long> dp = prev;
        
        for (int idx = 1; idx < nrows; ++idx) {
            std::vector<long long> left(ncols);
            std::vector<long long> right(ncols);
            
            left[0] = prev[0];
            for (int jdx = 1; jdx < ncols; ++jdx) {
                left[jdx] = std::max(prev[jdx], left[jdx-1] - 1);
            }
            
            right[ncols-1] = prev[ncols-1];
            for (int jdx = ncols-2; jdx >= 0; --jdx) {
                right[jdx] = std::max(prev[jdx], right[jdx+1] - 1);
            }
            
            for (int jdx = 0; jdx < ncols; ++jdx) {
                dp[jdx] = std::max(left[jdx], right[jdx]) + points[idx][jdx];
            }
            prev = dp;
        }
        
        long long result = dp[0];
        for (const auto& val : dp) {
            result = std::max(result, val);
        }
        
        return result;
    }
};

// #bugs = 1