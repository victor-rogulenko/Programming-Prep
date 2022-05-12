// LeetCode: 46. Permutations
// Created by Victor Rogulenko
// May 12, 2022

// This solution is the same as 47. Permutations II (has duplicate ints)

// Given an array nums of distinct integers, return all 
// the possible permutations. You can return the answer in any order.

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include <cassert>
#include <vector>
#include <queue>
#include <algorithm> // std::sort
#include <iostream>

class Solution {
    std::queue<int> positions;
    std::vector<int> values;
    std::vector<int> candidate;
    std::vector<std::vector<int>> result;
public:
    Solution() {};

    void buildUniquePermutation(int idx, int min_allowed_idx) {
        if (idx == values.size()) {
            result.push_back(candidate);
            return;
        }
        for (int jdx = 0; jdx < positions.size(); ++jdx) {
            int cur_position = positions.front();
            positions.pop();

            if (cur_position >= min_allowed_idx) {
                candidate[cur_position] = values[idx];
                if ((idx + 1 == values.size()) || (values[idx] != values[idx + 1])) {
                    buildUniquePermutation(idx + 1, 0);
                } else {
                    buildUniquePermutation(idx + 1, cur_position + 1);
                }
            }

            positions.push(cur_position);
        }
    };

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        // Initiate all the variables
        values = nums;
        candidate = std::vector<int>(values.size());
        std::sort(values.begin(), values.end());
        for (int idx = 0; idx < values.size(); ++idx) {
            positions.push(idx);
        }

        buildUniquePermutation(0, 0);
        return result;
    };    
};

void PrintVectorOfVectors(std::vector<std::vector<int>> output) {
    for (auto& vec : output) {
        for (auto elm : vec) {
            std::cout << elm << " ";
        }
        std::cout << "\n";
    }
    std::cout << "********\n";
}

void TestCase(std::vector<int> test) {
    std::vector<std::vector<int>> result = Solution().permute(test);
    PrintVectorOfVectors(result); 
}

void RunTestCases() {
    TestCase({1, 1});
    TestCase({1, 2});
    TestCase({1, 1, 1});
    TestCase({1, 2, 3, 4});
    TestCase({1, 1, 1, 1, 1, 1});
    TestCase({1, 2, 3});
    TestCase({1, 1, 2});
}

int main() {
    RunTestCases();
    return 0;
}