// LeetCode: 120. Triangle
// 120-Triangle.cpp
// Created by Victor Rogulenko
// [2022-06-13 12:17]	

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, you may move to either 
// index i or index i + 1 on the next row.

// Follow up: Could you do this using only O(n) extra space, 
// where n is the total number of rows in the triangle?

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -10^4 <= triangle[i][j] <= 10^4

// MAJOR IDEA: Store cur and prev row min paths. Update iteratively

#include <vector>
#include <algorithm> // std::min

class Solution {
public:
    int minimumTotal(const std::vector<std::vector<int>>& triangle) {
        std::vector<int> minPathPrevRow;
        std::vector<int> minPathCurRow(1, 0);
        int result;
        
        for (auto& row : triangle) {
            int row_len = row.size();
            minPathPrevRow = minPathCurRow;
            minPathCurRow = std::vector<int>(row_len);
            
            minPathCurRow[0] = minPathPrevRow[0] + row[0];
            if (row_len < 2) {
                result = minPathCurRow[0];
                continue;
            }
            minPathCurRow[row_len-1] = minPathPrevRow[row_len-2] + row[row_len-1];
            
            result = std::min(minPathCurRow[0], minPathCurRow[row_len-1]);
            
            for (int idx = 1; idx + 1 < row_len; ++idx) {
                minPathCurRow[idx] = std::min(
                    minPathPrevRow[idx - 1], minPathPrevRow[idx]
                ) + row[idx];
                result = std::min(result, minPathCurRow[idx]);
            }
        }
        
        return result;
    }
};

// #bugs = 3