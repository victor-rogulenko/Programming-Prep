// LeetCode: 1091. Shortest Path in Binary Matrix
// 1091-Shortest-Path-in-Binary-Matrix.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given an n x n binary matrix grid, return the length of the 
// shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell 
// (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected 
// (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <vector>
#include <queue>
#include <utility> // std::pair

class Solution {
    const int INF = (int)(1e6);
    
public:
    void updateNeighborsOfNode(int idx, int jdx,
                               const std::vector<std::vector<int>>& grid,
                               std::vector<std::vector<int>>& dist,
                               std::queue<std::pair<int, int>>& Q) {
        
        for (int lr = -1; lr <= 1; ++lr) {
            for (int ud = -1; ud <= 1; ++ud) {
                if (lr == 0 && ud == 0) {
                    continue;
                }
                
                if (idx + ud >= 0 && idx + ud < grid.size() &&
                    jdx + lr >= 0 && jdx + lr < grid.size() &&
                    grid[idx + ud][jdx + lr] != 1 &&
                    dist[idx + ud][jdx + lr] > dist[idx][jdx] + 1) {
                    
                    dist[idx + ud][jdx + lr] = dist[idx][jdx] + 1;
                    Q.push(std::make_pair(idx + ud, jdx + lr));
                }
            }
        }
    }
    
    int shortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> Q;
        std::vector<std::vector<int>> dist(grid.size(), 
                                           std::vector<int>(grid.size(), 
                                                            INF));
        
        if (grid[0][0] == 1) {
            return -1;
        }
        
        dist[0][0] = 1;
        Q.push(std::make_pair(0, 0));
        
        while (!Q.empty()) {
            auto node = Q.front();
            Q.pop();
            updateNeighborsOfNode(node.first, node.second, grid, dist, Q);
        }
        
        return (dist[grid.size() - 1][grid.size() - 1] < INF ? 
                dist[grid.size() - 1][grid.size() - 1] : 
                -1);
    }
};