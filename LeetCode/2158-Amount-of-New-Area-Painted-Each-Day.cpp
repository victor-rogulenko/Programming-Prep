// LeetCode: 2158. Amount of New Area Painted Each Day
// 2158-Amount-of-New-Area-Painted-Each-Day.cpp
// Created by Victor Rogulenko
// [2022-07-25 14:05]	

// There is a long and thin painting that can be represented by a number line. 
// You are given a 0-indexed 2D integer array paint of length n, where 
// paint[i] = [starti, endi]. This means that on the ith day you need to paint 
// the area between starti and endi.
// Painting the same area multiple times will create an uneven painting so you 
// only want to paint each area of the painting at most once.
// Return an integer array worklog of length n, where worklog[i] is the amount 
// of new area that you painted on the ith day.

// 1 <= paint.length <= 10^5
// paint[i].length == 2
// 0 <= starti < endi <= 5 * 10^4

// MAJOR IDEA 1. Merge intervals. Store painted segments in a hash map. 
// For each new segment, use upper_bound to find the first existing segment after 
// the current one. Take care of the previous segment. 
// Time: O(n log m), where m is the length of the fence.
// Memory: O(n). We have up to n intervals to store.

// MAJOR IDEA 2. Jump line. For a day i, try painting all areas in the range. 
// If the area is empty, set the value on the number line to end_i, and increment 
// the amount painted on that day. If the area has been painted previously, jump 
// to the end of the painted range (which was recorded on the number line on a previous day).
// Time: O(n + m), where m is the length of the fence.
// Memory: O(n + m).
// Works only when m is small. Not in this problem.

// SOLUTION 1. Ordered Set

#include <vector>
#include <algorithm> //std::max

class Solution {
public:
    std::vector<int> amountPainted(const std::vector<std::vector<int>>& paint) {
        std::vector<int> result(paint.size());
        std::map<int, int> painted;
        int idx = 0;
        for (auto& area : paint) {
            int left = area[0], right = area[1];
            auto curIt = painted.upper_bound(left);
            result[idx] = right - left;
            // Check for intersections with a preceeding segment:
            if (curIt != painted.begin()) {
                auto prevIt = std::prev(curIt);
                if (prevIt->second >= left) {
                    result[idx] -= std::min(right, prevIt->second) -
                        std::max(prevIt->first, left);
                    left = prevIt->first;
                    right = std::max(right, prevIt->second);
                }
            }
            // Now iterate through areas starting AFTER area[0] and before area[1]
            while (curIt != painted.end() && curIt->first <= right) {
                result[idx] -= std::min(right, curIt->second) - curIt->first;
                right = std::max(right, curIt->second);
                painted.erase(curIt++);
            }
            painted[left] = right;
            ++idx;
        }       
        return result;
    }
};

// #bugs = 1

// 
//          [  ]

// [      ]
//          [  ]

//        [      ]
//          [  ]

//        [   ]
//          [  ]

//            [   ]
//          [  ]

//                [      ]
//          [  ]


// Solution 2. Jump line

std::vector<int> amountPainted(const std::vector<std::vector<int>>& paint) {
    std::vector<int> line(50001);
    std::vector<int> result(paint.size());

    for (int idx = 0; idx < paint.size(); ++idx) {
        int start_i = paint[idx][0];
        int end_i = paint[idx][1];

        while (start_i < end_i) {
            int jump = std::max(start_i + 1, line[start_i]);
            result[i] += (line[start_i] == 0);
            // Create the jump
            line[start_i] = std::max(line[start_i], end_i);
            start_i = jump;
        }
    }

    return result;
}