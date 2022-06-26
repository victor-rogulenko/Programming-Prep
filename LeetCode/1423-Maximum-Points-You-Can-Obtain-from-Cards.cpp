// LeetCode: 1423. Maximum Points You Can Obtain from Cards
// 1423-Maximum-Points-You-Can-Obtain-from-Cards.cpp
// Created by Victor Rogulenko
// [2022-06-26 22:51]	

// There are several cards arranged in a row, and each card has 
// an associated number of points. The points are given in the integer 
// array cardPoints.
// In one step, you can take one card from the beginning or from the end of 
// the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum 
// score you can obtain.

// 1 <= cardPoints.length <= 10^5
// 1 <= cardPoints[i] <= 10^4
// 1 <= k <= cardPoints.length

// MAJOR IDEA: Sum up last k elements. Set right pointer to size - k, 
// left to -1. Move both pointers on each iteration, update the candidate 
// sum and store the greatest value of it

#include <vector>
#include <algorithm> // std::accumulate

class Solution {
public:
    int maxScore(const std::vector<int>& cardPoints, int k) {
        int numCards = cardPoints.size();
        int result = std::accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int candidate = result;
        
        for (int idx = 0; idx < k; ++idx) {
            candidate += cardPoints[idx] - 
                         cardPoints[numCards - k + idx];
            result = std::max(result, candidate);
        }
        
        return result;
    }
};

// result = 4
// candidate = 4
// left = -1
// right = 1