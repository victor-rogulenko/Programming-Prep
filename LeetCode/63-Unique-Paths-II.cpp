// LeetCode: 63. Unique Paths II
// 63-Unique-Paths-II.cpp
// Created by Victor Rogulenko
// [2022-05-20 13:00]  

// You are given an m x n integer array grid. There is a robot initially 
// located at the top-left corner (i.e., grid[0][0]). The robot tries to move 
// to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move 
// either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that 
// the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach 
// the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal 
// to 2 * 10^9.

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.

#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
        int nrows = obstacleGrid.size();
        int ncols = obstacleGrid[0].size();
        std::vector<int> prev(ncols + 1, 0);
        prev[1] = 1;
        std::vector<int> cur(ncols + 1, 0);
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 1; jdx <= ncols; ++jdx) {
                cur[jdx] = 0;
                if (obstacleGrid[idx][jdx-1] == 0) {
                    cur[jdx] += prev[jdx] + cur[jdx-1];
                }
            }
            prev = cur;
        }
        
        return cur[ncols];
    }
};