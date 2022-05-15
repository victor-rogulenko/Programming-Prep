// LeetCode: 26. Remove Duplicates from Sorted Array
// 26-Remove-Duplicates-from-Sorted-Array.cpp

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int from = 1, to = 1;
        while (from < nums.size()) {
            while (from < nums.size() && nums[from] == nums[from - 1]) {
                ++from;
            }
            if (from == nums.size()) {
                break;
            }
            nums[to] = nums[from];
            ++from;
            ++to;
        }
        return to;
    }
};