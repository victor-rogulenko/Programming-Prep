// LeetCode: 2274. Maximum Consecutive Floors Without Special Floors
// 293-2274-Maximum-Consecutive-Floors-Without-Special-Floors.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// Alice manages a company and has rented some floors of a building as office 
// space. Alice has decided some of these floors should be special floors, 
// used for relaxation only.
// You are given two integers bottom and top, which denote that Alice has 
// rented all the floors from bottom to top (inclusive). You are also given 
// the integer array special, where special[i] denotes a special floor 
// that Alice has designated for relaxation.
// Return the maximum number of consecutive floors without a special floor.

// 1 <= special.length <= 10^5
// 1 <= bottom <= special[i] <= top <= 10^9
// All the values of special are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int result = 0;
        sort(special.begin(), special.end());

        int cur = 0;
        while ((cur < special.size()) && (bottom > special[cur])) {
            ++cur;
        }
        if ((cur == special.size()) || (top < special[0]) || 
            (bottom > special[special.size()-1])) {
            return top - bottom + 1;
        }
        if ((cur < special.size()) && (bottom < special[cur])) {
            result = max(result, special[cur] - bottom);
        }
        int next = cur + 1;
        while ((next < special.size()) && (top > special[next])) {
            result = max(result, special[next] - special[cur] - 1);
            ++cur;
            ++next;
        }

        if (next < special.size()) {
            if (top == special[next]) {
                result = max(result, top - special[cur] - 1);
            } else {
                result = max(result, top - special[cur]);
            }
        } else {
            result = max(result, top - special[next-1]);
        }
        return result;
    }
};

void TestCase(int bottom, int top, vector<int> input, int expected) {
    int result = Solution().maxConsecutive(bottom, top, input);
    std::cout << "result = " << result << ", expected = " << expected << "\n";
    assert(result == expected);
}

void RunTestCases() {
    TestCase(2, 9, {4,6}, 3);
    TestCase(6, 8, {7,6,8}, 0);
    TestCase(2, 6, {4,6,8}, 2);
    TestCase(2, 4, {1}, 3);
    TestCase(2, 4, {10}, 3);
    TestCase(2, 4, {4}, 2);
}

int main() {
    RunTestCases();
    return 0;
}