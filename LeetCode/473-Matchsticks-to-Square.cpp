// LeetCode: 473. Matchsticks to Square
// 473-Matchsticks-to-Square.cpp
// Created by Victor Rogulenko
// [2022-07-12 13:44]

// You are given an integer array matchsticks where matchsticks[i] is 
// the length of the ith matchstick. You want to use all the matchsticks 
// to make one square. You should not break any stick, but you can link 
// them up, and each matchstick must be used exactly one time.
// Return true if you can make this square and false otherwise.
// 1 <= matchsticks.length <= 15
// 1 <= matchsticks[i] <= 10^8

// MAJOR IDEA. This problem is an instance of the well-known Bin Packing Problem, 
// which has been proven to be NP-complete, so it is not possible to implement 
// a solution that takes less than exponential time.

// MAJOR IDEA 1. DFS. O(4^N). Try to add each matchstick into each side. Sort matchsticks
// in nonincreasing order to speed up.

// MAJOR IDEA 2. DP + memoization with bitmap. O(N*2^N). TBD

// SOLUTION 1. DFS

class Solution {
public:
    bool check(const std::vector<int>& matchsticks, int idx,
              int sum1, int sum2, int sum3, int sum4) {
        if (sum1 > groupSum || sum2 > groupSum || sum3 > groupSum ||
           sum4 > groupSum) {
            return false;
        }
        if (idx == matchsticksSize) {
            return (sum1 == sum2 && sum2 == sum3 && sum3 == sum4);
        }
        
        bool option1 = check(matchsticks, idx+1, 
                             sum1 + matchsticks[idx],
                             sum2, sum3, sum4);

        bool option2 = check(matchsticks, idx+1, 
                             sum1, sum2  + matchsticks[idx], 
                             sum3, sum4);
        
        bool option3 = check(matchsticks, idx+1, 
                             sum1,sum2, 
                             sum3  + matchsticks[idx], sum4);
        
        bool option4 = check(matchsticks, idx+1, 
                             sum1, sum2, sum3, 
                             sum4  + matchsticks[idx]);
        
        return (option1 || option2 || option3 || option4);
    }
    
    bool makesquare(std::vector<int>& matchsticks) {
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        int perimeter = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        groupSum = perimeter / 4;
        if (groupSum * 4 != perimeter) {
            return false;
        }
        matchsticksSize = matchsticks.size();
        return check(matchsticks, 0, 0, 0, 0, 0);
    }
private:
    int groupSum;
    int matchsticksSize;
};

// #bugs = 1

// Should have O(N) time complexity <-- WRONG! Didn't read the instructions carefully
// We only have up to 15 matchsticks

// The question is, can we split the vector into 4 groups of equal sums?
// Finding the sum of each group takes O(N): sum everything up and divide by 4 = S
// If at least one matchstick is longer than S, the answer is false

// But how do we check that we can allocate the matchsticks into those groups?
// Sorting won't work because we only have O(N) time

// We have to ask 3 times: 
// - can we build a group of matchstiks with the sum equal to S
// - eliminate all the matchsticks in the group and repeat

// Maybe use a priority queue. 
// Put a new element until the cur sum becomes > S
// Pop the biggest element, insert the next element, check\

// Seems too complicated. This one should have a simpler solution