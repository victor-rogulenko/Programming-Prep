// LeetCode: 2276. Count Integers in Intervals
// 293-2276-Count-Integers-in-Intervals.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// Given an empty set of intervals, implement a data structure that can:

// Add an interval to the set of intervals.
// Count the number of integers that are present in at least one interval.
// Implement the CountIntervals class:

// CountIntervals() Initializes the object with an empty set of intervals.
// void add(int left, int right) Adds the interval [left, right] to the set 
// of intervals.
// int count() Returns the number of integers that are present in at least 
// one interval.
// Note that an interval [left, right] denotes all the integers x where 
// left <= x <= right.

// 1 <= left <= right <= 10^9
// At most 10^5 calls in total will be made to add and count.
// At least one call will be made to count.

#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
public:
    CountIntervals() {       
    }

    int CountIntersections(int left, int right) {
        // use set::lower_bound
    }
    
    void add(int left, int right) {
        int overlap = CountIntersections(left, right);
        result += (right - left + 1) - overlap;
        // add the interval into the storage
    }
    
    int count() {
        return result;
    }
private:
    vector<pair<int, int>> intervals;
    int result = 0;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

// void TestCase(vector<int> input, int expected) {
//     int result = Solution().largestCombination(input);
//     std::cout << "result = " << result << ", expected = " << expected << "\n";
//     assert(result == expected);
// }

void RunTestCases() {
//    TestCase({16,17,71,62,12,24,14}, 4);
}

int main() {
    RunTestCases();
    return 0;
}