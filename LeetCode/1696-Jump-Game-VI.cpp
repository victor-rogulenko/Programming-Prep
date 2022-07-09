// LeetCode: 1696. Jump Game VI
// 1696-Jump-Game-VI.cpp
// You are given a 0-indexed integer array nums and an integer k.
// You are initially standing at index 0. In one move, you can jump 
// at most k steps forward without going outside the boundaries of the array. 
// That is, you can jump from index i to any index in the range 
// [i + 1, min(n - 1, i + k)] inclusive.
// You want to reach the last index of the array (index n - 1). 
// Your score is the sum of all nums[j] for each index j you visited in the array.
// Return the maximum score you can get.
// 1 <= nums.length, k <= 10^5
// -10^4 <= nums[i] <= 10^4

// MAJOR IDEA 1. DP+Heap. O(N log N). Keep a heap of pairs <score, idx>. At each step, pop values with
// unacceptable indeces, then push top score + nums[idx]

// MAJOR IDEA 2. DP+Deque. O(N). Keep a deque of pairs <score, idx>. At each step, pop front values
// with (distance from idx) > k. Calculate current score and pop back scores smaller then current score.

// SOLUTION 1. DP+Heap

#include <vector>
#include <utility> // std::pair
#include <priority_queue>
#include <cassert>

class Solution {
public:
    int maxResult(const std::vector<int>& nums, int k) {
        // For each pair, first elm is the score at idx, second elm is idx
        std::priority_queue<std::pair<int, int>> heap;
        heap.push({nums[0], 0});
        int cur_score = nums[0];
        
        for (int idx = 1; idx < nums.size(); ++idx) {
            while (!heap.empty() && heap.top().second + k < idx) {
                heap.pop();
            }
            // The heap cannot become completely empty
            // assert(!heap.empty());
            cur_score = heap.top().first + nums[idx];
            heap.push({cur_score, idx});
        }
        
        return cur_score;
    }
};

// queue: {-87, 3}, {13, 4}, {58, 5}

// [1, 2, 10, -100, 0, 45]
// dp[idx] = max [i = 1..k](dp[idx-i]) + nums[idx]
// i = pos of the last nonnegative int in nums up to idx-1
// or the pos of the first occurance of the greatest number 
// (if all are negative)

// If k >= 2, 
// dp = 1, 3, 13, -87, 13, 58 
// What if we make all nums nonnegative?
// [101, 102, 110, 0, 100, 145]
// dp = 101, 203, 313, 313, 413, 558 
// -> need to move back to the actual numbers, but how?
// Track the number of jumps?

// SOLUTION 2. DP+Deque

class Solution {
public:
    int maxResult(const std::vector<int>& nums, int k) {
        // For each pair, first elm is the score at idx, second elm is idx
        std::deque<std::pair<int, int>> dq;
        dq.push_back({nums[0], 0});
        int cur_score = nums[0];
        for (int idx = 1; idx < nums.size(); ++idx) {
            while (dq.front().second + k < idx) {
                dq.pop_front();
            }
            // assert(!dq.empty());
            cur_score = dq.front().first + nums[idx];
            while (!dq.empty() && dq.back().first <= cur_score) {
                dq.pop_back();
            }
            dq.push_back({cur_score, idx});
        }
        
        return cur_score;
    }
};
