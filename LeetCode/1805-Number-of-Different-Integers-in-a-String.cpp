// LeetCode: 1805. Number of Different Integers in a String
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <set>

bool checkInt(char ch) {
    return ((ch >= '0') && (ch <= '9'));
}

int numDifferentIntegers(std::string word) {
    std::set<std::string> different_ints;
    int idx = 0;
    while (idx < word.length()) {
        // Look for the start of a new int
        while ((idx < word.length()) && (!checkInt(word[idx]))) {
            ++idx;
        }
        if (idx == word.length()) {
            break;
        }
        // Look for the end of a new int
        int jdx = idx;
        while ((jdx < word.length()) && (checkInt(word[jdx]))) {
            ++jdx;
        }
        --jdx;
        // Get rid of leading zeros;
        while ((idx < jdx) && (word[idx] == '0')) {
            ++idx;
        }     
        different_ints.insert(word.substr(idx, jdx-idx+1));
        idx = jdx + 1;
    }  
    return (different_ints.size());      
}

void RunTestCases() {
    assert(numDifferentIntegers("a123bc34d8ef34") == 3);
    assert(numDifferentIntegers("leet1234code234") == 2);
    assert(numDifferentIntegers("a1b01c001") == 1);
    assert(numDifferentIntegers("00000") == 1);
    assert(numDifferentIntegers("0000aa0000aa") == 1);
    assert(numDifferentIntegers("0000aa0000aa12z1") == 3);
}

int main() {
    RunTestCases();
    return 0;
}