// LeetCode: 130. Surrounded Regions
// 130-Surrounded-Regions.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given an m x n matrix board containing 'X' and 'O', capture all 
// regions that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that 
// surrounded region.

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

#include <vector>

class Solution {
    int nrows;
    int ncols;
    std::vector<std::vector<bool>> visited;
public:
    void dfs(int cur_idx, int cur_jdx,
             std::vector<std::vector<char>>& board) {
        if (board[cur_idx][cur_jdx] == 'X') {
            return;
        }
        
        board[cur_idx][cur_jdx] = 'V';
        visited[cur_idx][cur_jdx] = true;
        
        for (int idx = -1; idx <= 1; ++idx) {
            for (int jdx = -1; jdx <= 1; ++jdx) {
                if (idx != jdx && idx * jdx == 0 &&
                   cur_idx + idx >= 0 && cur_idx + idx < nrows &&
                   cur_jdx + jdx >= 0 && cur_jdx + jdx < ncols &&
                   !visited[cur_idx + idx][cur_jdx + jdx] &&
                   board[cur_idx + idx][cur_jdx + jdx] != 'X') {
                    
                    dfs(cur_idx + idx, cur_jdx + jdx, board);
                }
            }
        }
    }
    
    void solve(std::vector<std::vector<char>>& board) {
        nrows = board.size();
        ncols = board[0].size();
        visited = std::vector<std::vector<bool>>(nrows, std::vector<bool>(ncols, false));
        
        for (int idx = 0; idx < nrows; ++idx) {
            dfs(idx, 0, board);
            dfs(idx, ncols-1, board);
        }
        
        for (int jdx = 0; jdx < ncols; ++jdx) {
            dfs(0, jdx, board);
            dfs(nrows-1, jdx, board);    
        }
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                if (board[idx][jdx] == 'V') {
                    board[idx][jdx] = 'O';
                } else {
                    board[idx][jdx] = 'X';
                }
            }
        }
    }
};