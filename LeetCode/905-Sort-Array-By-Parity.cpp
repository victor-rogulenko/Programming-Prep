// LeetCode: 905. Sort Array By Parity

#include <vector>
#include <cassert>
#include <algorithm>

std::vector<int> sortArrayByParity(const std::vector<int>& nums) {
    std::vector<int> result(nums.size());
    int even_idx = 0;
    int odd_idx = result.size() - 1;
    for (auto cur : nums) {
        if (cur % 2 == 0) {
            result[even_idx] = cur;
            ++even_idx;
        } else {
            result[odd_idx] = cur;
            --odd_idx;
        }
    }
    return result;
}

bool CheckArrayIsSortedByParity(const std::vector<int>& nums) {
    if (nums.size() < 1) {
        return true;
    }
    int idx = 0;
    while ((idx < nums.size()) && (nums[idx] % 2 == 0)) {
        ++idx;
    }
    while ((idx < nums.size()) && (nums[idx] % 2 == 1)) {
        ++idx;
    }
    return (idx == nums.size());
}

bool CheckTestCase(std::vector<int> input, std::vector<int> result) {
    if (!CheckArrayIsSortedByParity(result)) {
        return false;
    }
    if (result.size() != input.size()) {
        return false;
    }
    std::sort(input.begin(), input.end());
    std::sort(result.begin(), result.end());
    for (auto idx = 0; idx < input.size(); ++idx) {
        if (input[idx] != result[idx]) {
            return false;
        }
    }
    return true;
}

void RunTestCases() {
    assert(CheckTestCase(sortArrayByParity({3, 1, 2, 4}), {2, 4, 3, 1}));
    assert(CheckTestCase(sortArrayByParity({0}), {0}));
}

int main() {
    RunTestCases();
    return 0;
}