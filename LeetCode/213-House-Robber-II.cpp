// LeetCode: 213. House Robber II
// 213-House-Robber-II.cpp

// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed. All houses at this 
// place are arranged in a circle. That means the first house is the neighbor 
// of the last one. Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses were 
// broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without 
// alerting the police.

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

// MAJOR IDEA: do 2 iterations: robbing the first house and not robbing it

#include <vector>
#include <utility> // std::pair

class Solution {
    int num_houses;
public:
    int tryRobberyPattern(const std::vector<int>& nums, 
                          bool robFirst) {
        std::vector<std::pair<int,int>> maxMoney(nums.size(), {0,0});
        // First: current house is robbed
        // Second: current house is not robbed, so we can do whatever 
        // with the previous houses
        
        if (robFirst) {
            maxMoney[0].first = nums[0];
        }
        
        for (int idx = 1; idx < num_houses; ++idx) {
            maxMoney[idx].first = maxMoney[idx-1].second + nums[idx];
            maxMoney[idx].second = std::max(maxMoney[idx-1].first,
                                            maxMoney[idx-1].second);
        }
        
        if (robFirst) {
            maxMoney[num_houses-1].first = 0;
        }
        
        return std::max(maxMoney[num_houses-1].first,
                        maxMoney[num_houses-1].second);
    }
    
    int rob(const std::vector<int>& nums) {
        num_houses = nums.size();
        if (num_houses == 1) {
            return nums[0];
        }
        
        return std::max(tryRobberyPattern(nums, true),
                        tryRobberyPattern(nums, false));              
    }
};