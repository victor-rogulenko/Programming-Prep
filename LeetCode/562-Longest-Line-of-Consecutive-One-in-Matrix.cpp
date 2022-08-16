// LeetCode: 562. Longest Line of Consecutive One in Matrix
// 562-Longest-Line-of-Consecutive-One-in-Matrix.cpp

// Given an m x n binary matrix mat, return the length of the 
// longest line of consecutive one in the matrix.
// The line could be horizontal, vertical, diagonal, or anti-diagonal.
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10^4
// 1 <= m * n <= 10^4
// mat[i][j] is either 0 or 1.

// MAJOR IDEA 1. Implementation. Check if the cell is a starting point 
// given direction, then calculate the length.
// Time: O(MN). Space: O(1).
// MAJOR IDEA 2. DP[dir][jdx], dir: 1 of 4 directions, jdx are columns

// SOLUTION 1. Straightforward Implementation

const int dirRow[4] = {1, 0, 1, 1};
const int dirCol[4] = {0, 1, 1, -1};

class Solution {
public:
    int longestLine(const std::vector<std::vector<int>>& mat) {
        int result = 0;
        nrows = mat.size();
        ncols = mat[0].size();
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                for (int dir = 0; dir < 4; ++dir) {
                    if (isStart(mat, idx, jdx, dir)) {
                        result = std::max(result, 
                                          calcLineLength(mat, idx, 
                                                         jdx, dir));
                    }
                }
            }
        }
        return result;
    }
private:
    int nrows, ncols;
    bool isStart(const std::vector<std::vector<int>>& mat,
                 int idx, int jdx, int dir) {
        if (mat[idx][jdx] != 1) {
            return false;
        }
        idx -= dirRow[dir];
        jdx -= dirCol[dir];
        if (idx < 0 || jdx < 0 || idx >= nrows || jdx >= ncols ||
           mat[idx][jdx] == 0) {
            return true;
        } else {
            return false;
        }        
    }
    
    int calcLineLength(const std::vector<std::vector<int>>& mat,
                       int idx, int jdx, int dir) {
        int result = 0;
        while (idx >= 0 && jdx >= 0 && idx < nrows && jdx < ncols &&
              mat[idx][jdx] == 1) {
            ++result;
            idx += dirRow[dir];
            jdx += dirCol[dir];
        }
        return result;
    }
};

// SOLUTION 2: Dynamic Programming

#include <vector>

// const int row[4] = {0, 1, 1, 1};
const int col[4] = {1, 0, 1, -1};

class Solution {
public:
    int longestLine(const std::vector<std::vector<int>>& mat) {
        int result = 0;
        int nrows = mat.size();
        int ncols = mat[0].size();
        std::vector<std::vector<int>> dp(4, std::vector<int>(ncols + 2, 0));
        for (int idx = 0; idx < nrows; ++idx) {
            // Horizontal traverse: prev line does not count
            dp[0] = std::vector<int>(ncols + 2, 0);
            auto dpPrev = dp;
            for (int jdx = 0; jdx < ncols; ++jdx) {
                for (int dir = 0; dir < 4; ++dir) {
                    // jdx + 1 accounts for going outside the boundaries
                    dp[dir][jdx + 1] = (dpPrev[dir][jdx + 1 - col[dir]] + 1) * mat[idx][jdx];
                    if (dir == 0) {
                        // Horizontal traverse: prev line does not count
                        dpPrev[dir][jdx + 1] = dp[dir][jdx + 1];
                    }
                    result = std::max(result, dp[dir][jdx + 1]);
                }
            }
        }
        return result;
    }
};

// #bugs = 1