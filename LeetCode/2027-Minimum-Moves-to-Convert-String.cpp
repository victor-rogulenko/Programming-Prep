// LeetCode: 2027. Minimum Moves to Convert String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

int minimumMoves(std::string s) {
    int ctr = 0;
    int idx = 0;
    while (idx < s.length()) {
        if (s[idx] == 'X') {
            ++ctr;
            idx += 3;
        } else {
            ++idx;
        }
    }
    return ctr;   
}

void RunTestCases() {
    assert(minimumMoves("XXX") == 1);
    assert(minimumMoves("XXOX") == 2);
    assert(minimumMoves("OOOO") == 0);
    assert(minimumMoves("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX") == 12);
}

int main() {
    RunTestCases();
    return 0;
}