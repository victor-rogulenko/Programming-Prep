// LeetCode: 2270. Number of Ways to Split Array
// 78-2270-Number-of-Ways-to-Split-Array.cpp
// Created by Victor Rogulenko
// May 14, 2022

#include <cassert>
#include <string>
#include <iostream>
#include <numeric>
#include <vector>

// You are given a 0-indexed integer array nums of length n.
// nums contains a valid split at index i if the following are true:
//  The sum of the first i + 1 elements is greater than or equal 
// to the sum of the last n - i - 1 elements.
// There is at least one element to the right of i. That is, 0 <= i < n - 1.
// Return the number of valid splits in nums.

// 2 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5

class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int result = 0;

        long long int right_sum = 0;
        for (auto val : nums) {
            right_sum += val;
        }

        right_sum -= nums[0];
        long long int left_sum = nums[0];
        

        for (int idx = 1; idx <= nums.size() - 1; ++idx) {
            if (left_sum >= right_sum) {
                ++result;
            }
            left_sum += nums[idx];
            right_sum -= nums[idx];
        }
        return result;        
    }
};

void TestCase(std::vector<int> input, int expected) {
    int result = Solution().waysToSplitArray(input);
    std::cout << "result = " << result << ", expected = " << expected << "\n";
    assert(result == expected);
}

void RunTestCases() {
    TestCase(std::vector<int>{10,4,-8,7}, 2);
    TestCase(std::vector<int>{2,3,1,0}, 2);
    TestCase(std::vector<int>{0, 10}, 0);
    TestCase(std::vector<int>{0, -10}, 1);
}

int main() {
    RunTestCases();
    return 0;
}