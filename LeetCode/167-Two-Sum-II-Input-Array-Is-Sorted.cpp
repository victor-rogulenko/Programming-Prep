// LeetCode: 167. Two Sum II - Input Array Is Sorted
// 167-Two-Sum-II-Input-Array-Is-Sorted.cpp
// Created by Victor Rogulenko
// [2022-06-09 22:14]  

// Given a 1-indexed array of integers numbers that is already sorted 
// in non-decreasing order, find two numbers such that they add up to a 
// specific target number. Let these two numbers be numbers[index1] and 
// numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one 
// as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. 
// You may not use the same element twice.
// Your solution must use only constant extra space.

// 2 <= numbers.length <= 3 * 10^4
// -1000 <= numbers[i] <= 1000
// numbers is sorted in non-decreasing order.
// -1000 <= target <= 1000
// The tests are generated such that there is exactly one solution.

// MAJOR IDEA: Update 2 pointers: ++start, if target > sum, 
// --finish otherwise. Return if target == sum

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        int start = 0, finish = numbers.size() - 1;
        while (start <= finish) {
            if (numbers[start] + numbers[finish] == target) {
                return {start + 1, finish + 1};
            }
            if (numbers[start] + numbers[finish] < target) {
                ++start;
            } else {
                --finish;
            }
        };
        return {0, 0};
    }
};