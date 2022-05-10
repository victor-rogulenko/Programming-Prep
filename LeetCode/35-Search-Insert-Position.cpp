// LeetCode: 35. Search Insert Position
// Created by Victor Rogulenko
// May 10, 2022

// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. If not, return the index 
// where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// 1 <= nums.length <= 10^4
// -10^4 < nums[i], target < 10^4
// All the integers in nums are unique.
// nums is sorted in ascending order.

#include <cassert>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int start = 0;
    int finish = nums.size() - 1;
    while (start <= finish) {
        int mid = start + (finish - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            finish = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

void RunTestCases() {
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    assert(searchInsert(nums, 9) == 4);

    nums = {-1, 0, 3, 5, 9, 12};
    assert(searchInsert(nums, 2) == 2);

    nums = {100000};
    assert(searchInsert(nums, 100000) == 0);

    nums = {100000};
    assert(searchInsert(nums, 2) == 0);

    nums = {1, 2, 3, 4};
    assert(searchInsert(nums, 3) == 2);

    nums = {1, 2, 3, 4};
    assert(searchInsert(nums, 4) == 3);

    std::vector<int> nums_new = {1, 2};
    assert(searchInsert(nums_new, 500) == 2);    
}

int main() {
    RunTestCases();
    return 0;
}