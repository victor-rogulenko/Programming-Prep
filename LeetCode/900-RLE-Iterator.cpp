// LeetCode: 900. RLE Iterator
// 900-RLE-Iterator.cpp
// Created by Victor Rogulenko
// [2022-08-17 16:39]

// We can use run-length encoding (i.e., RLE) to encode 
// a sequence of integers. In a run-length encoded array of 
// even length encoding (0-indexed), for all even i, encoding[i] 
// tells us the number of times that the non-negative integer 
// value encoding[i + 1] is repeated in the sequence.
// For example, the sequence arr = [8,8,8,5,5] can be encoded 
// to be encoding = [3,8,2,5]. encoding = [3,8,0,9,2,5] and 
// encoding = [2,8,1,8,2,5] are also valid RLE of arr.
// Given a run-length encoded array, design an iterator that 
// iterates through it.
// Implement the RLEIterator class:
// - RLEIterator(int[] encoded) Initializes the object with 
// the encoded array encoded.
// - int next(int n) Exhausts the next n elements and returns 
// the last element exhausted in this way. If there is no element 
// left to exhaust, return -1 instead.
// 2 <= encoding.length <= 1000
// encoding.length is even.
// 0 <= encoding[i] <= 10^9
// 1 <= n <= 10^9
// At most 1000 calls will be made to next.

// MAJOR IDEA: Compute prefix sums. Store current pos. On each query, 
// move pos and bin search to find the next position greater 
// than or equal to pos
// Time: O(N log N). Space: O(N)

#include <vector>
#include <algorithm> // std::lower_bound

class RLEIterator {
public:
    RLEIterator(const std::vector<int>& encoding) {
        prefixSum.resize(encoding.size()/2);
        values.resize(encoding.size()/2);
        prefixSum[0] = encoding[0];
        values[0] = encoding[1];
        for (int idx = 1; idx < encoding.size()/2; ++idx) {
            prefixSum[idx] = prefixSum[idx - 1] + encoding[idx * 2];
            values[idx] = encoding[idx * 2 + 1];
        }
    }
    
    int next(int n) {
        pos += n;
        auto iter = std::lower_bound(prefixSum.begin(), prefixSum.end(), pos);
        if (iter == prefixSum.end()) {
            return -1;
        }
        int idx = std::distance(prefixSum.begin(), iter);
        return values[idx];
    }
    
private:
    long long pos = 0;
    std::vector<int> values;
    std::vector<long long> prefixSum;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

// #bugs = 1