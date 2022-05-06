// LeetCode: 1209. Remove All Adjacent Duplicates in String II
// Created by Victor Rogulenko
// May XX, 2022

#include <cassert>
#include <stack>
#include <string>
#include <algorithm> // std::reverse

struct CharWithCtr {
    CharWithCtr(char ch_, int ctr_) : ch(ch_), ctr(ctr_) {};
    char ch;
    int ctr;
};

std::string StackToString(std::stack<CharWithCtr>& ch_stack) {
    std::string result = "";
    while (!ch_stack.empty()) {
        result += ch_stack.top().ch;
        ch_stack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
};

// 1 <= s.length <= 10^5
// 2 <= k <= 10^4
std::string removeDuplicates(std::string s, int k) {
    // Initialize stack
    std::stack<CharWithCtr> ch_stack;
    ch_stack.push(CharWithCtr(s[0], 1));

    // Iterate over all chars in s starting from 1 (0 is taken care of)
    // Add a char in a stack, update its ctr of duplicates
    // If ctr reaches k, do pop k times
    for (int idx = 1; idx < s.length(); ++idx) {
        CharWithCtr new_elm(s[idx], 1);
        if ((!ch_stack.empty()) && (ch_stack.top().ch == s[idx])) {
            new_elm.ctr = ch_stack.top().ctr + 1;
        }
        ch_stack.push(new_elm);

        if (ch_stack.top().ctr == k) {
            for (int jdx = 0; jdx < k; ++jdx) {
                ch_stack.pop();
            }
        }
    }
   
    // Convert the stack to a string and return it;
    s = StackToString(ch_stack);
    return s;        
};

void RunTestCases() {
    assert(removeDuplicates("abcd", 2) == "abcd");
    assert(removeDuplicates("deeedbbcccbdaa", 3) == "aa");
    assert(removeDuplicates("pbbcggttciiippooaais", 2) == "ps");
    assert(removeDuplicates("a", 2) == "a");
    assert(removeDuplicates("aaaaaaaaaaa", 2) == "a");
    assert(removeDuplicates("aaaaabbaaaaa", 2) == "");
    assert(removeDuplicates("aaaaaaaaaa", 10) == "");
}

int main() {
    RunTestCases();
    return 0;
}