// LeetCode: 74. Search a 2D Matrix
// 74-Search-a-2D-Matrix.cpp
// Created by Victor Rogulenko
// [2022-06-25 22:16]	

// Write an efficient algorithm that searches for a value target in an m x n 
// integer matrix matrix. This matrix has the following properties:
// - Integers in each row are sorted from left to right.
// - The first integer of each row is greater than the last integer of 
// the previous row.

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -10^4 <= matrix[i][j], target <= 10^4

// MAJOR IDEA: 2 bin searches. Build an auxiliary vector of first elements
// to use in the first bin search

#include <vector>
#include <algorightm> // std::upper_bound

class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        std::vector<int> rowHeads(matrix.size());
        int idx = 0;
        for (const auto& row : matrix) {
            rowHeads[idx] = row[0];
            ++idx;
        }
        
        auto rowIt = std::upper_bound(rowHeads.begin(), rowHeads.end(), target);
        if (rowIt == rowHeads.begin()) {
            return false;
        }
        
        int rowIdx = std::distance(rowHeads.begin(), rowIt) - 1;
        
        auto elmIt = std::upper_bound(matrix[rowIdx].begin(), matrix[rowIdx].end(), target);
        
        if (elmIt == matrix[rowIdx].begin()) {
            return false;
        }
        --elmIt;
        
        return (*elmIt == target);
    }
};