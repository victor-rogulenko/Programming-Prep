// LeetCode: 2267. Check if There Is a Valid Parentheses String Path
// 2267-Check-if-There-Is-a-Valid-Parentheses-String-Path.cpp
// Created by Victor Rogulenko
// May 15, 2022

#include <cassert>
#include <vector>
#include <set>

class Solution {
public:
    void addPathsToSet(const std::set<int>& input, int val, std::set<int>& result) {
        for (const auto& elm : input) {
            if (elm + val >= 0) {
                result.insert(elm + val);
            }
        }
    }

    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        std::vector<std::vector<std::set<int>>> valid_paths(
            n_rows + 1, std::vector<std::set<int>>(n_cols + 1));

        valid_paths[1][0].insert(0);
        
        for (int idx = 1; idx <= n_rows; ++idx) {
            for (int jdx = 1; jdx <= n_cols; ++jdx) {
                int cur = (grid[idx-1][jdx-1] == '(' ? 1 : -1);
                
                addPathsToSet(valid_paths[idx-1][jdx], cur, valid_paths[idx][jdx]);
                addPathsToSet(valid_paths[idx][jdx-1], cur, valid_paths[idx][jdx]);
            }
        }

        return (valid_paths[n_rows][n_cols].find(0) != 
                valid_paths[n_rows][n_cols].end());
    }
};

// int case_num = 1;

// void TestCase(int input, int expected) {
//     int result = Solution().method(input);
//     std::cout << "Case #" << case_num << ": expected = " << expected <<
//         ", result = " << result << "\n";
//     ++case_num;
//     assert(expected == result);
// }

// void RunTestCases() {
//     TestCase(2, 2);
// }

int main() {
    // RunTestCases();
    return 0;
}