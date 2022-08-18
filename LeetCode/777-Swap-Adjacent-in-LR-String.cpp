// LeetCode: 777. Swap Adjacent in LR String
// 777-Swap-Adjacent-in-LR-String.cpp
// Created by Victor Rogulenko
// [2022-08-18 12:26]

// In a string composed of 'L', 'R', and 'X' characters, 
// like "RXXLRXRXL", a move consists of either replacing 
// one occurrence of "XL" with "LX", or replacing one occurrence 
// of "RX" with "XR". Given the starting string start and the 
// ending string end, return True if and only if there exists 
// a sequence of moves to transform one string to the other.
// 1 <= start.length <= 10^4
// start.length == end.length
// Both start and end will only consist of characters in 'L', 'R', and 'X'.

// MAJOR IDEA: 2 pointers
// Need to check 3 rules:
// 1. Compressed strings (i.e. without X) are the same
// 2. All Ls in start are to the right of Ls in end
// 3. All Rs in start are to the left of Rs in end
// Time: O(N). Space: O(1)

#include <string>

class Solution {
public:
    // Need to check 3 rules:
    // 1. Compressed strings (i.e. without X) are the same
    // 2. All Ls in start are to the right of Ls in end
    // 3. All Rs in start are to the left of Rs in end
    bool canTransform(const std::string& start, 
                      const std::string& end) {
        int N = start.length();
        for (int sIdx = 0, eIdx = 0; (sIdx < N) || (eIdx < N); ) {
            // Skip X's
            if (sIdx < N && start[sIdx] == 'X') {
                ++sIdx;
            } else if (eIdx < N && end[eIdx] == 'X') {
                ++eIdx;
            } else {
                // Check Rule 1
                if ((sIdx < N && eIdx >= N) || 
                    (sIdx >= N && eIdx < N) || 
                    (start[sIdx] != end[eIdx])) {
                    return false;
                }
                // Check Rules 2 and 3
                if ((sIdx < N) && 
                    (start[sIdx] == 'L' && sIdx < eIdx) || // Rule 2
                    (start[sIdx] == 'R') && sIdx > eIdx) { // Rule 3
                    return false;
                }
                
                ++sIdx;
                ++eIdx;
            }
        }
        return true;
    }
};

// #bugs = 1