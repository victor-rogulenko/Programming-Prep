// LeetCode: 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// 1465-Maximum-Area-of-a-Piece-of-Cake-After-Horizontal-and-Vertical-Cuts.cpp
// Created by Victor Rogulenko
// [2022-07-02 23:48]	

// You are given a rectangular cake of size h x w and two arrays of integers 
// horizontalCuts and verticalCuts where:
// horizontalCuts[i] is the distance from the top of the rectangular cake to 
// the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to 
// the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal 
// and vertical position provided in the arrays horizontalCuts and verticalCuts. 
// Since the answer can be a large number, return this modulo 10^9 + 7.

// 2 <= h, w <= 10^9
// 1 <= horizontalCuts.length <= min(h - 1, 10^5)
// 1 <= verticalCuts.length <= min(w - 1, 10^5)
// 1 <= horizontalCuts[i] < h
// 1 <= verticalCuts[i] < w
// All the elements in horizontalCuts are distinct.
// All the elements in verticalCuts are distinct.

// MAJOR IDEA: Sort vertical and horizontal cuts. Find max vertical and horizonal 
// slices. Multiply them to get the result.

#include <vector>
#include <algorithm> // std::sort

const int modulo = (int)(1e9) + 7;

class Solution {
public:
    int maxArea(int h, int w, 
                std::vector<int>& horizontalCuts, 
                std::vector<int>& verticalCuts) {
        long long int maxHeight = maxLength(h, horizontalCuts);
        long long int maxWidth = maxLength(w, verticalCuts);
        return (maxHeight * maxWidth) % modulo;
    }

private:
    int maxLength(int len, std::vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        int result = 0;
        int start = 0;
        for (auto& cut : cuts) {
            result = std::max(result, cut - start);
            start = cut;
        }
        
        return std::max(result, len - cuts.back());
    }
};