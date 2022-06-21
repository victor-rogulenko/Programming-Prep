// LeetCode: 1642. Furthest Building You Can Reach
// 1642-Furthest-Building-You-Can-Reach.cpp
// Created by Victor Rogulenko
// [2022-06-22 02:13]	

// You are given an integer array heights representing the heights of buildings, 
// some bricks, and some ladders.
// You start your journey from building 0 and move to the next building by 
// possibly using bricks or ladders.
// While moving from building i to building i+1 (0-indexed),
// If the current building's height is greater than or equal to the next 
// building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, 
// you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use 
// the given ladders and bricks optimally.
// 1 <= heights.length <= 10^5
// 1 <= heights[i] <= 10^6
// 0 <= bricks <= 10^9
// 0 <= ladders <= heights.length

// MAJOR IDEA: Greedy. Cover all deltas with bricks. Push deltas into a max heap.
// If bricks count becomes negative, replace the max delta from the heap with
// a ladder

#include <vector>
#include <algorightm> // std::push_heap, std::pop_heap

class Solution {
public:
    int furthestBuilding(const std::vector<int>& heights, 
                         int bricks, int ladders) {
        int num_bldgs = heights.size();
        std::vector<int> heap;
        int idx = 0;
        
        for (; idx + 1 < num_bldgs; ++idx) {
            int delta = heights[idx+1] - heights[idx];
            if (delta <= 0) {
                continue;
            }
            
            heap.push_back(delta);
            std::push_heap(heap.begin(), heap.end());
            bricks -= delta;
            
            if (bricks < 0) {
                --ladders;
                bricks += heap[0];
                std::pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            }
            
            if (ladders < 0) {
                break;
            }
        }
        
        return idx;
    }
};

// #bugs = 3

// Your input [4,2,7,6,9,14,12], 
// bricks = 0, 
// ladders = 1
// cur_bldg = 3
// heap: 5