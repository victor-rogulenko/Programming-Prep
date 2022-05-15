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

    void add(int left, int right) {
        auto iter = intervals.lower_bound(make_pair(left, left));
        if (iter != intervals.begin()) {
            --iter;
        }
        // iter is the first interval that starts to the left of [left, right]
        // or the leftmost element in the set (if it's to the right of [left, right])

        int combined_left = left;
        int combined_right = right;

        // Find all the intersections of current intervals with [left, right] 
        vector<pair<int, int>> to_be_removed;

        while (iter != intervals.end() && iter->first <= right) {
            // If iter does not intersect [left, right], skip it
            if (iter->second < left - 1) {
                ++iter;
                continue;
            }
            // Merge iter with the new interval [left, right]
            combined_left = min(combined_left, iter->first);
            combined_right = max(combined_right, iter->second);

            to_be_removed.push_back(*iter);
            ++iter;
        }

        // Remove all the redundanct intervals;
        for (auto& elm : to_be_removed) {
            result -= (elm.second - elm.first + 1);
            intervals.erase(elm);
        }

        // add combined_left, combined_right
        intervals.insert(make_pair(combined_left, combined_right));
        result += combined_right - combined_left + 1;
    }
    
    int count() {
        return result;
    }

private:
    set<pair<int, int>> intervals;
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