// LeetCode: 60. Permutation Sequence // 60-Permutation-Sequence.cpp
// Created by Victor Rogulenko
// May 12, 2022

// Given n and k, return the kth permutation sequence.
// 1 <= n <= 9
// 1 <= k <= n!

#include <cassert>
#include <string>
#include <vector>
#include <algorithm> // std::next_permutation for testing
#include <iostream>

std::string makeFirstPermutationOfSizeN(int n) {
    std::string result = "";
    for (int idx = 1; idx <= n; ++idx) {
        result += (char)(idx + (int)('0'));
    }
    return result;
};

std::string getPermutation(int n, int position_code) {
    std::string result = "";

    // Need to enumerate the positions from 0 to n! - 1
    --position_code;

    // Calculate n!: max permutation
    int factorial = 1;
    for (int idx = 1; idx <= n; ++idx) {
        factorial *= idx;
    }

    if ((position_code > factorial) || (position_code < 0)) {
        return result;
    }

    // Create the default string
    std::string temp = makeFirstPermutationOfSizeN(n);

    // Fill in the resulting string according to the position code;
    for (int position = n; position > 0; --position) {
        factorial /= position;
        int selected_idx = position_code / factorial;
        result += temp[selected_idx];

        // Remove selected_idx from temp and repeat
        temp = temp.substr(0, selected_idx) + temp.substr(selected_idx + 1);

        position_code %= factorial;
    }

    return result;
}

void TestCase(int n, int k) {
    std::string expected = makeFirstPermutationOfSizeN(n);
    for (int cnt = 1; cnt < k; ++cnt) {
        std::next_permutation(expected.begin(), expected.end());
    }

    std::string result = getPermutation(n, k);
    std::cout << "expected = " << expected << ", " << "result = " << result << "\n";

    assert(result == expected);
}

void RunTestCases() {
    TestCase(3, 3);
    TestCase(4, 9);
    TestCase(3, 1);
    TestCase(7, 1000);
    TestCase(7, 5000);
}

int main() {
    RunTestCases();
    return 0;
}