// LeetCode: 778. Swim in Rising Water
// 778-Swim-in-Rising-Water.cpp
// Created by Victor Rogulenko
// [2022-08-16 15:16]

// You are given an n x n integer matrix grid where each value 
// grid[i][j] represents the elevation at that point (i, j).
// The rain starts to fall. At time t, the depth of the water 
// everywhere is t. You can swim from a square to another 4-directionally 
// adjacent square if and only if the elevation of both squares 
// individually are at most t. You can swim infinite distances 
// in zero time. Of course, you must stay within the boundaries 
// of the grid during your swim.
// Return the least time until you can reach the bottom right 
// square (n - 1, n - 1) if you start at the top left square (0, 0).
// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// 0 <= grid[i][j] < n^2
// Each value grid[i][j] is unique.

// MAJOR IDEA 1: Bin search through all water levels from 0 to N^2. Check if 
// a water level is enough by running dfs from 0,0
// Time: O(N^2 log N^2). Space: O(N^2)
// MAJOR IDEA 2: Kruskal (discount set union)
// MAJOR IDEA 3: Heap

#include <vector>

const int moveX[4] = {1, 0, -1, 0};
const int moveY[4] = {0, 1, 0, -1};

class Solution {
public:
    int swimInWater(const std::vector<std::vector<int>>& grid) {
        N = grid.size();
        if (N == 1) {
            return 0;
        }
        int left = 0, right = N*N;
        while (left + 1 < right) {
            int mid = left + (right - left + 1) / 2;
            if (isTargetReachable(grid, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

private: 
    int N;
    std::vector<std::vector<bool>> reachable;
    
    bool isTargetReachable(const std::vector<std::vector<int>>& grid,
                          int waterLevel) {
        reachable = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));
        if (grid[0][0] <= waterLevel) {
            dfs(grid, waterLevel, 0, 0);    
        }
        return reachable[N-1][N-1];
    }
    
    void dfs(const std::vector<std::vector<int>>& grid,
             int waterLevel, int x, int y) {
        reachable[x][y] = true;
        for (int idx = 0; idx < 4; ++idx) {
            if (x + moveX[idx] >= 0 && x + moveX[idx] < N &&
                y + moveY[idx] >= 0 && y + moveY[idx] < N &&
                grid[x + moveX[idx]][y + moveY[idx]] <= waterLevel &&
                reachable[x + moveX[idx]][y + moveY[idx]] == false) {
                dfs(grid, waterLevel, x + moveX[idx], y + moveY[idx]);
            }
        }
    }
};

// #bugs = 1