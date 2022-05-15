// LeetCode: 2272. Substring With Largest Variance
// 2272-Substring-With-Largest-Variance.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// The variance of a string is defined as the largest difference between 
// the number of occurrences of any 2 characters present in the string. 
// Note the two characters may or may not be the same.
// Given a string s consisting of lowercase English letters only, 
// return the largest variance possible among all substrings of s.
// A substring is a contiguous sequence of characters within a string.

// 1 <= s.length <= 10^4
// s consists of lowercase English letters.

#include <cassert>
#include <string>
#include <vector>
#include <algorithm> // std::max

class Solution {
public:
    int largestVariance(std::string s) {
        int result = 0;

        // [MAJOR IDEA 1] Iterate over possible chars with min and max occurances
        // Compute the answer for each pair;
        for (char minCh = 'a'; minCh <= 'z'; ++minCh) {
            for (char maxCh = 'a'; maxCh <= 'z'; ++maxCh) {
                if (minCh == maxCh) {
                    continue;
                }

                int cur_res = -(int)(1e5);
                int cur_possible_max = 0;

                for (int idx = 0; idx < s.size(); ++idx) {
                    
                    // Default contribution to the variance
                    // if s[idx] is not minCh or maxCh
                    int cur_val = 0;

                    if (s[idx] == minCh) {
                        cur_val = -1;    
                    } else if (s[idx] == maxCh) {
                        cur_val = 1;
                    }

                    // [MAJOR IDEA 2] It might make sense to restart from idx
                    // if the variance becomes negative
                    cur_possible_max = std::max(cur_possible_max + cur_val, 
                                                cur_val);

                    cur_res += cur_val;

                    // [MAJOR IDEA 3] If s[idx] == minChar, we are allowed to restart
                    // whereever we want (use cur_possible_max)
                    // If not, need to continue as is: we might not have minChar in our
                    // history, and updating would skew the results
                    if (s[idx] == minCh) {
                        cur_res = std::max(cur_res, cur_possible_max);
                    }

                    result = std::max(result, cur_res);
                }
            }
        }
        return result;
    }
};

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