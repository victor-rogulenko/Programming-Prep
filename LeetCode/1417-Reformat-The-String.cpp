// LeetCode: 1417. Reformat The String
// Created by Victor Rogulenko

#include <string>
#include <stack>
#include <cmath> // std::abs
#include <cassert>

std::string reformat(std::string s) {
    std::stack<char> numbers_stack;
    std::stack<char> letters_stack;
    for (char ch : s) {
        if ((ch >= 'a') && (ch <= 'z')) {
            letters_stack.push(ch);
        } else {
            numbers_stack.push(ch);
        }
    }
    std::string result = "";
    if (std::abs((int)(numbers_stack.size()) - (int)(letters_stack.size())) > 1) {
        return result;
    }
    bool start_with_numbers;
    if (numbers_stack.size() > letters_stack.size()) {
        start_with_numbers = true;
    } else {
        start_with_numbers = false;
    }
    int ctr = s.size();
    char current_char;
    while (ctr > 0) {
        if (start_with_numbers) {
            current_char = numbers_stack.top();
            numbers_stack.pop();
        } else {
            current_char = letters_stack.top();
            letters_stack.pop();
        }
        result += current_char;
        start_with_numbers = !start_with_numbers;
        --ctr;
    }
    return result;    
}

bool checkStringIsReformated(std::string s) {
    if (!s.size()) {
        return true;
    }
    for (int idx = 1; idx < s.size(); ++idx) {
        if (((s[idx] >= '0') && (s[idx] <= '9') && (s[idx-1] >= '0') && (s[idx-1] <= '9')) || 
            ((s[idx] >= 'a') && (s[idx] <= 'z') && (s[idx-1] >= 'a') && (s[idx-1] <= 'z'))) {
            return false;
        }
    }
    return true;
}

void RunTestCases() {
    assert(checkStringIsReformated(reformat("a0b1c2")));
    assert(checkStringIsReformated(reformat("leetcode")));
    assert(checkStringIsReformated(reformat("1229857369")));
    assert(reformat("s") == "s");
    assert(reformat("1") == "1");  
    assert(checkStringIsReformated(reformat("abcd12345")));
}

int main(){
    RunTestCases();
    return 0;
}