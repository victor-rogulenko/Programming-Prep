// LeetCode: 278. First Bad Version
// Created by Victor Rogulenko
// May 10, 2022

#include <cassert>

// You are a product manager and currently leading a team to develop 
// a new product. Unfortunately, the latest version of your product 
// fails the quality check. Since each version is developed based on 
// the previous version, all the versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out 
// the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which returns 
// whether version is bad. Implement a function to find the first 
// bad version. You should minimize the number of calls to the API.

// 1 <= bad <= n <= 2^31 - 1

int bad;

bool isBadVersion(int version) {
    return (version >= bad);
}

int firstBadVersion(int n) {
    int start = 1;
    int finish = n;
    while (start < finish) {
        int mid = (start / 2) + (finish / 2);
        bool checkMid = isBadVersion(mid);
        if (checkMid) {
            finish = mid;
        } else {
            start = mid + 1;
        }
    }
    return finish;
}

void RunTestCases() {
    bad = 4;
    assert(firstBadVersion(5) == 4);

    bad = 1;
    assert(firstBadVersion(1) == 1);
    assert(firstBadVersion(2) == 1);
    assert(firstBadVersion(3) == 1);
    assert(firstBadVersion(4) == 1);

    bad = 10;
    assert(firstBadVersion(10) == 10);
    assert(firstBadVersion(10000) == 10);
    assert(firstBadVersion(100000000) == 10);
    assert(firstBadVersion(100000000) == 10);
    assert(firstBadVersion(2126753390) == 10);
    assert(firstBadVersion(1702766719) == 10);
}

int main() {
    RunTestCases();
    return 0;
}