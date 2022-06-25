// LeetCode: 74. Search a 2D Matrix
// 74-Search-a-2D-Matrix.cpp



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