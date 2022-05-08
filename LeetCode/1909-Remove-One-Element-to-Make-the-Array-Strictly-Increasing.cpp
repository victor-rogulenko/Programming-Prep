// LeetCode: 1909. Remove One Element to Make the Array Strictly Increasing  
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>

bool canBeIncreasing(const std::vector<int>& nums) {
    int ctr_candidates_for_removal = 0;
    for (int idx = 1; idx < nums.size(); ++idx) {
        if (nums[idx] > nums[idx-1]) {
            continue;
        }
        if ((idx + 1 == nums.size()) || (nums[idx-1] < nums[idx+1]) || 
             (idx == 1) || (nums[idx-2] < nums[idx]))  {
            ++ctr_candidates_for_removal;
        } else {
            return false;
        }
    }
    return (ctr_candidates_for_removal < 2);    
}

void RunTestCases() {
    std::vector<int> nums = {1,2,10,5,7};
    assert(canBeIncreasing(nums) == true);

    nums = {1,2,3};
    assert(canBeIncreasing(nums) == true);

    nums = {1,2,10};
    assert(canBeIncreasing(nums) == true);

    nums = {50, 1, 2, 10};
    assert(canBeIncreasing(nums) == true);

    nums = {50, 10};
    assert(canBeIncreasing(nums) == true);

    nums = {10, 20, 30, 5, 7, 9, 10};
    assert(canBeIncreasing(nums) == false);

    nums = {10, 20, 30, 5, 40, 50, 60};
    assert(canBeIncreasing(nums) == true);
}

int main() {
    RunTestCases();
    return 0;
}