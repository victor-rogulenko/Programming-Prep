// LeetCode: 581. Shortest Unsorted Continuous Subarray
// Created by Victor Rogulenko

#include <cassert>
#include <vector>

int findUnsortedSubarray(const std::vector<int>& nums) {
    if (nums.size() < 2) { 
        return 0;
    }
    bool minFound = false;
    bool maxFound = false;
    int min_value, max_value;
    for (size_t idx = 1; idx < nums.size(); ++idx) {
        if (nums[idx] < nums[idx - 1]) {
            if ((!minFound) || (min_value > nums[idx])) {
                minFound = true;
                min_value = nums[idx];
            }
            if ((!maxFound) || (max_value < nums[idx - 1])) {
                maxFound = true;
                max_value = nums[idx - 1];
            }            
        }
    }
    if (!maxFound) {
        return 0;
    }
    int min_real_idx = 0;
    while ((min_real_idx < nums.size()) && (nums[min_real_idx] <= min_value)) {
        ++min_real_idx;
    }

    int max_real_idx = nums.size() - 1;
    while ((max_real_idx >= 0) && (nums[max_real_idx] >= max_value)) {
        --max_real_idx;
    }
    return (max_real_idx - min_real_idx + 1);
}

void RunTests() {
    assert (findUnsortedSubarray({1}) == 0);
    assert (findUnsortedSubarray({10, 10, 10}) == 0);
    assert (findUnsortedSubarray({3, 2, 1}) == 3);
    assert (findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15}) == 5);
    assert (findUnsortedSubarray({1, 2, 3, 4}) == 0);
    assert (findUnsortedSubarray({100, 101, 6, 4, 8, 9, 10, 15}) == 8);
    assert (findUnsortedSubarray({-100000, 100000}) == 0);
    assert (findUnsortedSubarray({5, 10, 11, 6, 4, 8, 12, 13, 100, 14, 15}) == 11);
    assert (findUnsortedSubarray({1, 3, 2, 3, 3, 3, 3}) == 2);
}

int main() {
    RunTests();
    return 0;
}