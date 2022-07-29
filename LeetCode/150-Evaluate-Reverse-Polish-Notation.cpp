// LeetCode: 150. Evaluate Reverse Polish Notation
// 150-Evaluate-Reverse-Polish-Notation.cpp
// Created by Victor Rogulenko
// July 29, 2022

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, and /. Each operand may be an integer or 
// another expression.
// Note that division between two integers should truncate toward zero.
// It is guaranteed that the given RPN expression is always valid. 
// That means the expression would always evaluate to a result, and there will 
// not be any division by zero operation.
// 1 <= tokens.length <= 10^4
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

// MAJOR IDEA: Unwind iteratively from the back. Return result and position for next operand. 
// Alternatively, use a stack and iterate tokens from 0 to end
// Time: O(N). Space: O(N)

#include <vector>
#include <string>
#include <stack>

// SOLUTION 1

class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> st;
        
        for (int idx = 0; idx < tokens.size(); ++idx) {
            if (tokens[idx].back() < '0') {
                
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if (tokens[idx] == "+") {
                    st.push(a + b);
                } else if (tokens[idx] == "-") {
                    st.push(a - b);
                } else if (tokens[idx] == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
                
            } else {
                st.push(std::stoi(tokens[idx]));
            }
        }
        return st.top();
    }
};

// #bugs = 2
// careful with switch statement: it does not stop on just one case!







// SOLUTION 2

class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        auto result = parse(tokens, tokens.size() - 1);
        return result.second;
    }

private:
    std::pair<int,int> parse(const std::vector<std::string>& tokens, int pos) {
        if (tokens[pos].back() < '0') {  // if the token is an operator
            auto operandOne = parse(tokens, pos-1);
            auto operandTwo = parse(tokens, operandOne.first);
            int result;
            
            if (tokens[pos][0] == '+') {
                result = operandOne.second + operandTwo.second;
            } else if (tokens[pos][0] == '-') {
                result = operandTwo.second - operandOne.second;
            } else if (tokens[pos][0] == '*') {
                result = operandOne.second * operandTwo.second;
            } else {
                result = operandTwo.second / operandOne.second;
            }
            
            return {operandTwo.first, result};
            
        } else {
            return {pos-1, std::stoi(tokens[pos])};
        }
    }
};

// #bugs = 2
// careful with switch statement: it does not stop on just one case!