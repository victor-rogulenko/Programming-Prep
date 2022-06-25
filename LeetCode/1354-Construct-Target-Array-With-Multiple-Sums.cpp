// LeetCode: 1354. Construct Target Array With Multiple Sums
// 1354-Construct-Target-Array-With-Multiple-Sums.cpp
// Created by Victor Rogulenko
// [2022-06-25 21:22]  

// You are given an array target of n integers. From a starting array arr 
// consisting of n 1's, you may perform the following procedure :
// - let x be the sum of all elements currently in your array.
// - choose index i, such that 0 <= i < n and set the value of arr at index i to x.
// - You may repeat this procedure as many times as needed.
// Return true if it is possible to construct the target array from arr, 
// otherwise, return false.

// n == target.length
// 1 <= n <= 5 * 10^4
// 1 <= target[i] <= 10^9

// MAJOR IDEA: Build a max heap. Repeat maxElm %= (sum - maxElm) 
// until (maxElm == 1) or (sum - maxElm <= 0) or (sum - maxElm == 1)

#include <vector>
#include <priority_queue>
#include <algorithm> //std::sort

class Solution {
public:
    bool isPossible(const std::vector<int>& target) {
        long long int sum = std::accumulate(target.begin(), target.end(), 0LL);
        int size = target.size();
        std::priority_queue<int> queue(target.begin(), target.end());
        
        while (true) {
            int maxElm = queue.top();
            if (maxElm == 1 && sum == size) {
                return true;
            }
            sum -= maxElm;
            if (sum == 1) {
                return true;
            } else if (sum <= 0) {
                return false;
            }
            maxElm %= sum;
            if (maxElm == queue.top() || maxElm == 0) {
                return false;
            }
            sum += maxElm;
            queue.pop();
            queue.push(maxElm);
        }
        
        return false;
    }
};

// #bugs = 3

// [1,2]
// maxElm = 2
// sum = 3

// [9, 3, 5], sum = 17
// [9-(17-9) = 1, 3, 5], sum = 9
// [1, 3, 5-(9-5) = 1], sum = 5
// [1, 3-(5-3) = 1, 1], sum = 3   

// [1,1,1] 3
// [3,1,1] 5
// [5,1,1] 7
// [7,1,1] 9
// [9,1,1] 11
// [11,1,1] 13

// heap.top() % (sum_remaining)
// if no change, return false
// Still might take too much time
// log N updates x (N - all elements + smth? 
// How many times will we repeat elements? Less than log Value)

// [57, 17, 31]
// [9, 17, 31]
// [9, 17, 5]
// [9, 3, 5]
// [1, 3, 5]
// [1, 3, 1]
// [1, 1, 1]
