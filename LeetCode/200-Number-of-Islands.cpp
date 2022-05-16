// LeetCode: 200. Number of Islands
// 200-Number-of-Islands.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given an m x n 2D binary grid grid which represents a map 
// of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent 
// lands horizontally or vertically. You may assume all four edges of 
// the grid are all surrounded by water.

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include <vector>

class Solution {
    int nrows;
    int ncols;
    int result = 0;
public:
    void dfs(int idx, int jdx, std::vector<std::vector<char>>& grid) {
        if (grid[idx][jdx] == '0') {
            return;
        }
        
        grid[idx][jdx] = '0';
        
        for (int ud = -1; ud <= 1; ++ud) {
            for (int lr = -1; lr <= 1; ++lr) {
                if (lr != ud && lr*ud == 0 && 
                    idx + ud >= 0 && idx + ud < nrows &&
                    jdx + lr >= 0 && jdx + lr < ncols &&
                    grid[idx + ud][jdx + lr] != '0') {
                    
                    dfs(idx + ud, jdx + lr, grid);
                }
            }
        }
    }
    
    int numIslands(std::vector<std::vector<char>>& grid) { 
        nrows = grid.size();
        ncols = grid[0].size();
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                if (grid[idx][jdx] == '1') {
                    ++result;
                    dfs(idx, jdx, grid);
                }
            }
        }
        
        return result;
    }
};