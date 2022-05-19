// LeetCode: 329. Longest Increasing Path in a Matrix
// 329-Longest-Increasing-Path-in-a-Matrix.cpp
// Given an m x n integers matrix, return the length of the longest 
// increasing path in matrix.
// From each cell, you can either move in four directions: left, 
// right, up, or down. You may not move diagonally or move outside 
// the boundary (i.e., wrap-around is not allowed).

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

#include <vector>

class Solution {
    int nrows, ncols;
    std::vector<std::vector<int>> max_length;
public:
    void initialize(const std::vector<std::vector<int>>& matrix) {
        nrows = matrix.size();
        ncols = matrix[0].size();
        max_length = std::vector<std::vector<int>>(
            nrows, std::vector<int>(ncols, -1));        
    }
    
    bool canMove(const std::vector<std::vector<int>>& matrix,
                int idx, int jdx, int ud, int lr) {
        if ((idx + ud >= 0) && (idx + ud < nrows) &&
            (jdx + lr >= 0) && (jdx + lr < ncols) &&
            (ud * lr == 0) && (ud != lr) &&
            (matrix[idx][jdx] < matrix[idx + ud][jdx + lr])) {
            return true;
        }
        return false;
    }
    
    void calculateMaxLengthStartingFromHere(
        const std::vector<std::vector<int>>& matrix,
        int idx, int jdx) {
        
        if (max_length[idx][jdx] != -1) {
            return;
        }
        
        max_length[idx][jdx] = 1;
        
        for (int ud = -1; ud <= 1; ++ud) {
            for (int lr = -1; lr <= 1; ++lr) {
                if (canMove(matrix, idx, jdx, ud, lr)) {
                    if (max_length[idx + ud][jdx + lr] == -1) {
                        calculateMaxLengthStartingFromHere(
                            matrix, idx + ud, jdx + lr);
                    }
                    max_length[idx][jdx] = 
                        max(max_length[idx][jdx],
                            max_length[idx + ud][jdx + lr] + 1);
                }
            }
        }
    }
    
    int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
        initialize(matrix);
        int result = 0;
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                if (max_length[idx][jdx] == -1) {
                    calculateMaxLengthStartingFromHere(matrix, idx, jdx);
                }
                result = std::max(result, max_length[idx][jdx]);
            }
        }
        
        return result;
    }
};