// LeetCode: 1679. Max Number of K-Sum Pairs
// Created by Victor Rogulenko

#include <vector>
#include <unordered_map>
#include <cassert>

int maxOperations(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> pair_lookup;
    int result = 0;
    for (auto elm : nums) {
        if ((pair_lookup.find(elm) != pair_lookup.end()) &&
           (pair_lookup[elm] > 0)) {
            // Pair found; dec pair_lookup counter and inc result;
            --pair_lookup[elm];
            ++result;
        } else {
            // Pair not found. Add (k-elm) to pair_lookup;
            if (pair_lookup.find(k-elm) != pair_lookup.end()) {
                // Not the first time we see this value
                ++pair_lookup[k-elm];
            } else {
                pair_lookup[k-elm] = 1;
            }
        }  
    }
    return result;    
}

void RunTestCases() {
    std::vector<int> input({1, 2, 3, 4});
    int k = 5;
    assert (maxOperations(input, 5) == 2);
    input = {3, 1, 3, 4, 3};
    k = 6;
    assert (maxOperations(input, 6) == 1);
    input = {10};
    k = 10;
    assert (maxOperations(input, 10) == 0);
    input = {500000000, 500000000};
    k = 1000000000;
    assert (maxOperations(input, k) == 1);
    input = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    k = 2;
    assert (maxOperations(input, k) == 6);
    input = {10};
    k = 1000000000;
    assert (maxOperations(input, k) == 0);
    // input = {};
    // k = ;
    // assert (maxOperations(input, k) == );
}

int main() {
    RunTestCases();
    return 0;
}