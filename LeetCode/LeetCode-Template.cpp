// LeetCode: 
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

#include <cassert>

// Past new code here

int case_num = 1;

void TestCase(int input, int expected) {
    int result = Solution().method(input);
    std::cout << "Case #" << case_num << ": expected = " << expected <<
        ", result = " << result << "\n";
    ++case_num;
    assert(expected == result);
}

void RunTestCases() {
    TestCase(2, 2);
}

int main() {
    RunTestCases();
    return 0;
}