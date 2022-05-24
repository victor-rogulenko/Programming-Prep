// LeetCode: 32. Longest Valid Parentheses
// 32-Longest-Valid-Parentheses.cpp
// Created by Victor Rogulenko
// [2022-05-24 17:49]  

// Given a string containing just the characters '(' and ')', 
// find the length of the longest valid (well-formed) parentheses substring.

// 0 <= s.length <= 3 * 10^4
// s[i] is '(', or ')'.

// MAJOR IDEA: Store indeces of '(' in the stack. 
// Keep track of the last closing bracket seen with an empty stack

#include <string>
#include <stack>
#include <algorithm> // std::max

class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        
        int result = 0;
        int start_default = 0;
        std::stack<int> st;
        
        for (int idx = 0; idx < s.size(); ++idx) {
            if (s[idx] == '(') {
                st.push(idx);
            } else if (!st.empty()) {
                st.pop();
                int start = (st.empty() ? start_default : st.top() + 1);
                int candidate = idx - start + 1;
                result = std::max(result, candidate);
            } else {
                start_default = idx + 1;
            }
        }
        
        return result;
    }
};

// 012345
// (()

// start_default: 0
// idx: 2
// stack: 0 
// candidate: 2 - 1 + 1 
// result: 2

// #bugs: 0