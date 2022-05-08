// LeetCode: 2148. Count Elements With Strictly Smaller and Greater Elements
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>

int countElements(const std::vector<int>& nums) {
    if (nums.size() < 3) {
        return 0;
    }
    int maxNums = nums[0];
    int minNums = nums[0];
    for (auto& num : nums) {
        maxNums = (maxNums < num ? num : maxNums);
        minNums = (minNums > num ? num : minNums);
    }
    int result = 0;
    for (auto& num : nums) {
        result += ((num < maxNums) && (num > minNums));
    }
    return result;
}

// 1 <= nums.length <= 100
// -10^5 <= nums[i] <= 10^5

void RunTestCases() {
    std::vector<int> nums{11,7,2,15};
    assert(countElements(nums) == 2);

    nums = {-3,3,3,90};
    assert(countElements(nums) == 2);

    nums = {-3,3};
    assert(countElements(nums) == 0);

    nums = {-3};
    assert(countElements(nums) == 0);

    nums = {-3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    assert(countElements(nums) == 0);
}

int main() {
    RunTestCases();
    return 0;
}