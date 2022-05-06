// LeetCode: 1374. Generate a String With Characters That Have Odd Counts
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>

std::string generateTheString(int n) {
    std::string result = "";
    if (n % 2 == 1) {
        result.insert(0, n, 'a');
    } else {
        result.insert(0, n-1, 'a');
        result += 'b';
    }
    return result;    
}

// 1 <= n <= 500

void RunTestCases() {
    assert(generateTheString(1) == "a");
    assert(generateTheString(2) == "ab");
    assert(generateTheString(3) == "aaa");
}

int main() {
    RunTestCases();
    return 0;
}