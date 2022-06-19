// LeetCode: 54. Spiral Matrix
// 54-Spiral-Matrix.cpp
// Created by Victor Rogulenko
// [2022-06-19 14:46]

// Given an m x n matrix, return all elements of the matrix in spiral order.
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// MAJOR IDEA: Keep min_row, max_row, min_col, max_col, row_chg, col_chg, 
// is_row_movement (bool) and update careafully. 
// Iterate until (min_row <= max_row && min_col <= max_col)

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        int min_row = 0, max_row = matrix.size() - 1;
        int min_col = 0, max_col = matrix[0].size() - 1;
        std::vector<int> result;
        int row_it = 0, col_it = 0;
        bool row_movement = false;
        int row_chg = 1;
        int col_chg = 1;
        
        // 1 2 3 
        
        while (min_row <= max_row && min_col <= max_col) {
            result.push_back(matrix[row_it][col_it]);
            row_it += row_chg * (row_movement);
            col_it += col_chg * (1 - row_movement);
            
            if (col_it > max_col || col_it < min_col) {
                row_movement = true;
                col_chg *= -1;
                if (col_it > max_col) {
                    --col_it;
                    ++row_it;
                    ++min_row;
                }
                if (col_it < min_col) {
                    ++col_it;
                    --row_it;
                    --max_row;
                }                
            }

            if (row_it > max_row || row_it < min_row) {
                row_movement = false;
                row_chg *= -1;
                if (row_it > max_row) {
                    --row_it;
                    --col_it;
                    --max_col;
                }
                if (row_it < min_row) {
                    ++row_it;
                    ++col_it;
                    ++min_col;
                }                
            }
        }
        
        return result;
    }
};

// #bugs = 1
