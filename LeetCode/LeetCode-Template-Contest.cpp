// LeetCode: 
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

#include <bits/stdc++.h>
using namespace std;

// Past new code here

void TestCase(vector<int> input, int expected) {
    int result = Solution().maximumWhiteTiles(input, carpetLen);
    std::cout << "result = " << result << ", expected = " << expected << "\n";
    assert(result == expected);
}

void RunTestCases() {
    TestCase();
}

int main() {
    RunTestCases();
    return 0;
}