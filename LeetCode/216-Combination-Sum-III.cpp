// LeetCode: 216. Combination Sum III
// Created by Victor Rogulenko
// May 10, 2022

#include <cassert>
#include <vector>
// #include <iostream>

// Find all valid combinations of k numbers that sum up to n 
// such that the following conditions are true:
// - Only numbers 1 through 9 are used.
// - Each number is used at most once.

// 2 <= k <= 9
// 1 <= n <= 60

// void PrintVectorOfVectors(const std::vector<std::vector<int>>& output) {
//     for (auto& vect : output) {
//         for (auto& elm : vect) {
//             std::cout << elm << " ";
//         }
//         std::cout << "\n";
//     }
// }

std::vector<std::vector<int>> combinationSumGivenMaxMinElements(
    int ctr, int target_sum, int min_element, int max_element) {
    std::vector<std::vector<int>> result;
    if ((ctr == 0) && (target_sum == 0)) {
        result.push_back(std::vector<int>{0});
        return result;
    }

    if (target_sum < 0) {
        return result;
    }

    // Check if we can make a combo for n given the constraints
    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < ctr; ++i) {
        min_sum += (min_element + i);
        max_sum += (max_element - i);
    }
    if ((target_sum > max_sum) || (target_sum < min_sum) ||
        (ctr <= 0)) {
        return result;
    }

    for (int elm = max_element; elm >= min_element; --elm) {
        std::vector<std::vector<int>> temp = combinationSumGivenMaxMinElements(
            ctr - 1, target_sum - elm, min_element, elm - 1);
        if (temp.empty()) {
            continue;
        }
        for (auto& candidate : temp) {
            if ((candidate.size() == 1) && (candidate[0] == 0)) {
                candidate[0] = elm;
            } else {
                // push back elm and all of candidate
                candidate.push_back(elm);
            }
            result.push_back(candidate);
        }
    }
    return result;
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    return combinationSumGivenMaxMinElements(k, n, 1, 9);
}

void RunTestCases() {
    std::vector<std::vector<int>> result;
    assert(combinationSum3(4, 1) == result);

    result = {{1, 2, 4}};
    assert(combinationSum3(3, 7) == result);

    result = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    assert(combinationSum3(3, 9) == result);

    result = {{1, 4}, {2, 3}};
    assert(combinationSum3(2, 5) == result);

    result = {{3, 9}, {4, 8}, {5, 7}};
    assert(combinationSum3(2, 12) == result);

    result = {};
    assert(combinationSum3(5, 60) == result);
}

int main() {
    RunTestCases();
    return 0;
}