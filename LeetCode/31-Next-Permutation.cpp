// LeetCode: 31. Next Permutation // 31-Next-Permutation.cpp
// Created by Victor Rogulenko
// May 12, 2022

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include <cassert>
#include <vector>
#include <algorithm> // std::reverse, std::iter_swap, std::next_permutation (for testing)
#include <iostream>

// 1 5 1

template<class T>
typename std::vector<T>::iterator binSearchRightmostMinGreater(
    typename std::vector<T>::iterator start, 
    typename std::vector<T>::iterator finish, 
    T val) {
    
    while (start < finish) {
        auto mid = start + std::distance(start, finish) / 2;
        if (*mid > val) {
            start = mid + 1;
        } else {
            finish = mid;
        }
    }
    return finish - 1;
};

void nextPermutation(std::vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    // Fint the longest nonincreasing subsequence starting from end
    // It has no next permutation
    auto pivot_iter = nums.end() - 1;
    while ((pivot_iter != nums.begin()) && (*(pivot_iter - 1) >= *pivot_iter)) {
        --pivot_iter;
    }

    // If there's no next permutation (i.e. all elements are sorted in nonincreasing
    // order already), sort the string and return;
    if (pivot_iter == nums.begin()) {
        std::reverse(nums.begin(), nums.end());
        return;
    }

    // Otherwise, the required pivot is one step before:
    --pivot_iter;

    // Find the smallest element greater than *pivot_iter, swap with pivot_iter
    // and reverse the substring from pivot_iter + 1 to end
    auto rightmost_min_greater = binSearchRightmostMinGreater(
        pivot_iter + 1, nums.end(), *pivot_iter);
    std::iter_swap(pivot_iter, rightmost_min_greater);
    std::reverse(pivot_iter + 1, nums.end());

    // nums is now the next permutation
}

void TestCase(std::vector<int> nums) {
    auto expected = nums;
    for (auto idx = 0; idx < 100; ++idx) {
        std::next_permutation(expected.begin(), expected.end());
        nextPermutation(nums);        
        for (auto val : nums) {
            std::cout << val << " ";
        }
        std::cout << "\n*************************\n";

        assert(nums == expected);
    }
}

void RunTestCases() {
    TestCase({1, 2, 3});
    TestCase({3, 2, 1});
    TestCase({1, 1, 5});
    TestCase({1, 1, 5, 4, 6, 10});
    TestCase({1});
    TestCase({1, 3, 2});
    TestCase({2, 3, 1});
    TestCase({2, 1, 3});
    TestCase({3, 1, 2});
    TestCase({5, 4, 1, 2, 3});
    TestCase({4, 5, 3, 2, 1});
    TestCase({1,5,1});
}

int main() {
    RunTestCases();
    return 0;
}