// LeetCode: 304. Range Sum Query 2D - Immutable
// 304-Range-Sum-Query-2D-Immutable.cpp
// Created by Victor Rogulenko
// [2022-06-03 16:04]	

// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by 
// its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of 
// the elements of matrix inside the rectangle defined by its upper left 
// corner (row1, col1) and lower right corner (row2, col2).

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// -10^5 <= matrix[i][j] <= 10^5
// 0 <= row1 <= row2 < m
// 0 <= col1 <= col2 < n
// At most 10^4 calls will be made to sumRegion.

// MAJOR IDEA: res(row1,col1,row2,col2) = sum[row2][col2] + 
// sum[row1-1][col2] + sum[row2][col1-1] - sum[row1-1][col1-1]

#include <vector>

const int maxSize = 201;

class NumMatrix {
public:
    NumMatrix(const std::vector<std::vector<int>>& matrix) {
        nrows = matrix.size();
        ncols = matrix[0].size();
        
        for (int idx = 1; idx <= nrows; ++idx) {
            for (int jdx = 1; jdx <= ncols; ++jdx) {
                upperleft_sum[idx][jdx] = matrix[idx-1][jdx-1] + 
                    upperleft_sum[idx-1][jdx] + 
                    upperleft_sum[idx][jdx-1] - 
                    upperleft_sum[idx-1][jdx-1];
            }
        }
    };
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return upperleft_sum[row2+1][col2+1] - 
            upperleft_sum[row1][col2+1] -
            upperleft_sum[row2+1][col1] + 
            upperleft_sum[row1][col1];
    };
    
private:
    int upperleft_sum[maxSize][maxSize] = {0};
    int ncols;
    int nrows;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// #bugs = 1