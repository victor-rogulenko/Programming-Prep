// LeetCode: 528. Random Pick with Weight
// 528-Random-Pick-with-Weight.cpp
// Created by Victor Rogulenko
// [2022-08-15 15:26]	

// You are given a 0-indexed array of positive integers w where w[i] 
// describes the weight of the ith index.
// You need to implement the function pickIndex(), which randomly picks 
// an index in the range [0, w.length - 1] (inclusive) and returns it. 
// The probability of picking an index i is w[i] / sum(w).
// For example, if w = [1, 3], the probability of picking index 0 is 
// 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 
// 3 / (1 + 3) = 0.75 (i.e., 75%).

// 1 <= w.length <= 10^4
// 1 <= w[i] <= 10^5
// pickIndex will be called at most 10^4 times.

// MAJOR IDEA: Calculate partial sums. Generate a uniform random variable between 1
// and total sum. Return the index at which partial sums start exceeding the random value
// (find the index with binary search)
// Time: O(M log N). Space: O(N). N - #indeces, M - #queries

#include <vector>
#include <algorithm> // std::lower_bound
#include <random>  //  std::random_device, std::mt19937

class Solution {
public:
    Solution(const std::vector<int>& w) {
        runningSum.resize(w.size());
        for (int idx = 0; idx < w.size(); ++idx) {
            totalSum += w[idx];
            runningSum[idx] = totalSum;
        }
        
        std::random_device rd;
        randomNumberGenerator = std::mt19937(rd());
        distribution = std::uniform_int_distribution<int>(1, totalSum);
    }
    
    int pickIndex() {
        int pick = distribution(randomNumberGenerator);
        auto iter = std::lower_bound(runningSum.begin(), runningSum.end(), pick);
        return std::distance(runningSum.begin(), iter);
    }
    
private:
    std::vector<int> runningSum;
    int totalSum = 0;
    std::uniform_int_distribution<int> distribution;
    std::mt19937 randomNumberGenerator;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
        