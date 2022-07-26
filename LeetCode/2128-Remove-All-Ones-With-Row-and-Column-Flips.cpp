// LeetCode: 2128. Remove All Ones With Row and Column Flips
// 2128-Remove-All-Ones-With-Row-and-Column-Flips.cpp
// Created by Victor Rogulenko
// Jul 26, 2022

// You are given an m x n binary matrix grid.
// In one operation, you can choose any row or column and flip each value 
// in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
// Return true if it is possible to remove all 1's from grid using any number 
// of operations or false otherwise.
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is either 0 or 1.

// MAJOR IDEA: Math. Check all 2x2 submatrices. If the number of ones in any of 
// them is odd, the result is false. If nrows = 1 or ncols = 1, the result is true.
// Time: O(mn). Space: O(1)

#include <vector>

class Solution {
public:
    bool removeOnes(const std::vector<std::vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = grid[0].size();
        if (ncols == 1 || nrows == 1) {
            return true;
        }
        
        for (int idx = 0; idx + 1 < nrows; ++idx) {
            for (int jdx = 0; jdx + 1 < ncols; ++jdx) {
                int parity = (grid[idx][jdx] + grid[idx+1][jdx] + 
                              grid[idx][jdx+1] + grid[idx+1][jdx+1]) % 2;
                if (parity) {
                    return false;
                }
            }
        }
        
        return true;
    }
};