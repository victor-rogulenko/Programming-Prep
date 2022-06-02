// LeetCode: 867. Transpose Matrix
// 867-Transpose-Matrix.cpp
// Created by Victor Rogulenko
// June 2, 2022

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, 
// switching the matrix's row and column indices.

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 10^5
// -10^9 <= matrix[i][j] <= 10^9

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(
    	const std::vector<std::vector<int>>& matrix) {

        int nrows = matrix.size();
        int ncols = matrix[0].size();
        
        std::vector<int> row(nrows, 0);
        std::vector<std::vector<int>> result(ncols, row);
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                result[jdx][idx] = matrix[idx][jdx];
            }
        }
        
        return result;
    }
};

// #bugs = 1