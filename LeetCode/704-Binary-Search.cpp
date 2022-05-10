// LeetCode: 704. Binary Search
// Created by Victor Rogulenko
// May 10, 2022

// Given an array of integers nums which is sorted in ascending order, 
// and an integer target, write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// 1 <= nums.length <= 10^4
// -10^4 < nums[i], target < 10^4
// All the integers in nums are unique.
// nums is sorted in ascending order.

#include <cassert>
#include <vector>

int search(std::vector<int>& nums, int target) {
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
    return -1;
}

void RunTestCases() {
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    assert(search(nums, 9) == 4);

    nums = {-1, 0, 3, 5, 9, 12};
    assert(search(nums, 2) == -1);

    nums = {100000};
    assert(search(nums, 100000) == 0);

    nums = {100000};
    assert(search(nums, 2) == -1);

    nums = {1, 2, 3, 4};
    assert(search(nums, 3) == 2);

    nums = {1, 2, 3, 4};
    assert(search(nums, 4) == 3);

    std::vector<int> nums_new = {1, 2};
    assert(search(nums_new, 500) == -1);    
}

int main() {
    RunTestCases();
    return 0;
}