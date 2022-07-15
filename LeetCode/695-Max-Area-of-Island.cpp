// LeetCode: 695. Max Area of Island
// 695-Max-Area-of-Island.cpp
// Created by Victor Rogulenko
// [2022-07-16 00:34]

// You are given an m x n binary matrix grid. An island is a group of 1's 
// (representing land) connected 4-directionally (horizontal or vertical.) 
// You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

// MAJOR IDEA: Run BFS on each newly found land 1 and convert all visited 1's into 0's

// BUG: Updated 1's incorrectly when extracting from the queue. 
// Should have updated them when adding to the queue instead

#include <vector>
#include <queue>
#include <algorithm> // std::max

const std::pair<int, int> moves[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int result = 0;
        nrows = grid.size();
        ncols = grid[0].size();
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                if (grid[idx][jdx] == 1) {
                    int candidate = bfs(grid, idx, jdx);
                    result = std::max(result, candidate);
                }
            }
        }
        
        return result;
    }

private:
    int nrows, ncols;
    
    int bfs(std::vector<std::vector<int>>& grid, int cur_idx, int cur_jdx) {
        std::queue<std::pair<int, int>> q;
        q.push({cur_idx, cur_jdx});
        grid[cur_idx][cur_jdx] = 0;
        int result = 0;
        
        while (!q.empty()) {
            int idx = q.front().first;
            int jdx = q.front().second;
            q.pop();
            ++result;

            for (auto& move : moves) {
                if (isAcceptable(grid, idx + move.first, jdx + move.second)) {
                    q.push({idx + move.first, jdx + move.second});
                    grid[idx + move.first][jdx + move.second] = 0;
                }
            }
        }
        
        return result;
    }
    
    bool isAcceptable(const std::vector<std::vector<int>>& grid, 
                      int idx, int jdx) {
        if (idx >= 0 && jdx >= 0 && idx < nrows && jdx < ncols &&
            grid[idx][jdx] == 1) {
            return true;
        } else {
            return false;
        }
    }
};

// #bugs = 1