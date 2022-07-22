// LeetCode: 1293. Shortest Path in a Grid with Obstacles Elimination
// 1293-Shortest-Path-in-a-Grid-with-Obstacles-Elimination.cpp
// You are given an m x n integer matrix grid where each cell is either 0 (empty) 
// or 1 (obstacle). You can move up, down, left, or right from and to an 
// empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) 
// to the lower right corner (m - 1, n - 1) given that you can eliminate at 
// most k obstacles. If it is not possible to find such walk return -1.
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 40
// 1 <= k <= m * n
// grid[i][j] is either 0 or 1.
// grid[0][0] == grid[m - 1][n - 1] == 0

// MAJOR IDEA: BFS + quota as a state
// O(N * K)
// DO NOT USE DFS (yields TL)

#include <vector>
#include <algorithm> //std::min
#include <cstring> //std::memset

const int maxSize = 41;
const int INF = 10000;
const int move_row[4] = {1, 0, -1,  0};
const int move_col[4] = {0, 1,  0, -1};

struct State {
    int row, col, quota;
};

class Solution {
public:
    int shortestPath(const std::vector<std::vector<int>>& grid, int k) {
        initPaths(grid, k);
        calcPaths(grid);
        int result = selectBestResult();
        return (result < INF ? result : -1);
    }
    
private:
    int paths[maxSize][maxSize][maxSize*maxSize];
    int nrows, ncols, numObstacles;
    
    void calcPaths(const std::vector<std::vector<int>>& grid) {
        if (numObstacles >= nrows + ncols - 2) {
            paths[nrows-1][ncols-1][0] = nrows + ncols - 2;
            return;
        }
        
        std::queue<State> Q;
        Q.push({0, 0, numObstacles});
        
        while (!Q.empty()) {
            auto cur_state = Q.front();
            Q.pop();
            for (int moveIdx = 0; moveIdx < 4; ++moveIdx) {
                int y = cur_state.row + move_row[moveIdx];
                int x = cur_state.col + move_col[moveIdx];
                if (!isPermissible(y,x)) {
                    continue;
                }
                int quota = cur_state.quota - grid[y][x];
                if ((quota >= 0) &&
                    (paths[y][x][quota] > paths[cur_state.row][cur_state.col][cur_state.quota] + 1)) {
                    paths[y][x][quota] = paths[cur_state.row][cur_state.col][cur_state.quota] + 1;
                    Q.push({y,x,quota});
                }
            }
        }
    }
    
    bool isPermissible(int cur_row, int cur_col) {
        return (cur_row >= 0 && cur_col >= 0 && cur_row < nrows &&
               cur_col < ncols);
    }
    
    void initPaths(const std::vector<std::vector<int>>& grid, int k) {
        std::memset(paths, INF, sizeof(paths));
        for (int cnt = k; cnt >= 0; --cnt) {
            paths[0][0][cnt] = 0;
        }
        
        nrows = grid.size();
        ncols = grid[0].size();
        numObstacles = k;
    }
    
    int selectBestResult() {
        int result = INF;
        for (int cnt = numObstacles; cnt >= 0; --cnt) {
            result = std::min(result, paths[nrows-1][ncols-1][cnt]);
        }
        return result;
    }
};

// #bugs = 2
// TL exceeded